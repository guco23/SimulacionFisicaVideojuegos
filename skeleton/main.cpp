#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include <iostream>

#include "Vector3D.h"
#include "Particle.h"
#include "const.h"
#include "ParticleSystem.h"
#include "ParticleGenerator.h"
#include "UniformDistribution.h"
#include "NormalDistribution.h"
#include "ForceGenerator.h"
#include "Gravity.h"
#include "Wind.h"
#include "Torbellin.h"
#include "ParticleGenerator.h"
#include "RigidBody.h"
#include "GameManager.h"
#include <list>

std::string display_text = "This is a test";


using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;

RenderItem* esferaX;
RenderItem* esferaY;
RenderItem* esferaZ;
RenderItem* esferaC;

ParticleSystem partSys;
GameManager man;
std::list<RigidBody*> rigids;

// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);
	
	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);
	
	PxRigidStatic* suelo = gPhysics->createRigidStatic(PxTransform(0, -10, 0));
	PxShape* shape = CreateShape(PxBoxGeometry(100, 0.1, 100));
	suelo->attachShape(*shape);
	gScene->addActor(*suelo);

	RenderItem* i = new RenderItem(shape, suelo, { 0.8, 0.8, 0.8, 1 });

	//Instanciacion de las entidades en escena
	PxShape* sphere = CreateShape(PxSphereGeometry(1));
	Vector3D vectorX = Vector3D(5, 0, 0);
	Vector3D vectorY = Vector3D(0, 5, 0);
	Vector3D vectorZ = Vector3D(0, 0, 5);
	Vector3D vectorC = Vector3D(0, 0, 0);

	PxTransform* transformC = new PxTransform(PxVec3(vectorC.getX(), vectorC.getY(), vectorC.getZ()));
	//Valores del vector puestos directamente de forma provisional hasta que haga mi vector3
	PxTransform* transformX = new PxTransform(PxVec3(vectorX.getX(), vectorX.getY(), vectorX.getZ()));
	PxTransform* transformY = new PxTransform(PxVec3(vectorY.getX(), vectorY.getY(), vectorY.getZ()));
	PxTransform* transformZ = new PxTransform(PxVec3(vectorZ.getX(), vectorZ.getY(), vectorZ.getZ()));

	PxVec4 colorW(1, 1, 1, 1);
	PxVec4 colorR = PxVec4(1, 0, 0,1);
	PxVec4 colorG = PxVec4(0, 1, 0, 1);
	PxVec4 colorB = PxVec4(0, 0, 1, 1);

	esferaC = new RenderItem(sphere, transformC, colorW);
	esferaX = new RenderItem(sphere, transformX, colorR);
	esferaY = new RenderItem(sphere, transformY, colorG);
	esferaZ = new RenderItem(sphere, transformZ, colorB);

	//partSys = ParticleSystem(20.0, 700.0, Vector3D(0,0,0));
	//Particle* model = new Particle(Vector3D(0, 0, 0), Vector3D(0.2, 0.2, 0.2), 1, 0.999, 0.5);
	//model->DeregisterRender(); //Para que la partícula modelo no se renderice.

	//Distribution* dist = new UniformDistribution(-5, 10);
	//Particularizador particularizador = Particularizador();
	//particularizador.distVelY = dist;
	//particularizador.distVelX = dist;
	//particularizador.distVelZ = dist;

	//ParticleGenerator partGen1 = ParticleGenerator(model, 5.0, particularizador);
	//partSys.AddGenerator(partGen1);

	//ForceGenerator* gravity = new Gravity();
	//partSys.AddForce(gravity);

	//ForceGenerator* torbellin = new Torbellin(3, 30);
	//partSys.AddForce(torbellin);

	man = GameManager(&rigids, gScene, gPhysics);
	man.init();
}

// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	man.update(t);
	gScene->simulate(t);
	gScene->fetchResults(true);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	DeregisterRenderItem(esferaC);
	DeregisterRenderItem(esferaX);
	DeregisterRenderItem(esferaY);
	DeregisterRenderItem(esferaZ);

	// Delete de las parts
	/*
	for (Particle* part : parts)
		delete part;
	*/

	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
	}


//void GeneratePartFromCam() {
//	partSys.AddParticle(new Particle(Vector3D(GetCamera()->getEye().x, GetCamera()->getEye().y, GetCamera()->getEye().z),
//		Vector3D(- GetCamera()->getDir().x, - GetCamera()->getDir().y, - GetCamera()->getDir().z),
//		1, 0.999, 0.5));
//}


//void GeneratePartFromStatic(Vector3D pos, Vector3D dir) {
//	parts.push_back(new Proyectil(pos, dir,
//		1, 0.999, 0.5));
//}


// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	//case 'B': break;
	//case ' ':	break;
	case ' ':
	{
		man.Shoot();
		break;
	}
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
	man.CollisionDetected(actor1, actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}