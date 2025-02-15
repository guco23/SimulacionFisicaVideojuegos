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
#include "Muelle.h"
#include "Flotacion.h"
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

std::vector<ParticleSystem*> sys;

GameManager man;
std::list<RigidBody*> rigids;

// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport, PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(), true, gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	/*PxRigidStatic* suelo = gPhysics->createRigidStatic(PxTransform(0, -10, 0));
	PxShape* shape = CreateShape(PxBoxGeometry(100, 0.1, 100));
	suelo->attachShape(*shape);
	gScene->addActor(*suelo);*/

	//RenderItem* i = new RenderItem(shape, suelo, { 0.8, 0.8, 0.8, 1 });

	//Instanciacion de las entidades en escena
	PxShape* sphere = CreateShape(PxSphereGeometry(1));
	Vector3D vectorX = Vector3D(5, 0, 0);
	Vector3D vectorY = Vector3D(0, 5, 0);
	Vector3D vectorZ = Vector3D(0, 0, 5);
	Vector3D vectorC = Vector3D(0, 0, 0);

	PxTransform* transformC = new PxTransform(PxVec3(vectorC.getX(), vectorC.getY(), vectorC.getZ()));
	PxTransform* transformX = new PxTransform(PxVec3(vectorX.getX(), vectorX.getY(), vectorX.getZ()));
	PxTransform* transformY = new PxTransform(PxVec3(vectorY.getX(), vectorY.getY(), vectorY.getZ()));
	PxTransform* transformZ = new PxTransform(PxVec3(vectorZ.getX(), vectorZ.getY(), vectorZ.getZ()));

	PxVec4 colorW(1, 1, 1, 1);
	PxVec4 colorR = PxVec4(1, 0, 0, 1);
	PxVec4 colorG = PxVec4(0, 1, 0, 1);
	PxVec4 colorB = PxVec4(0, 0, 1, 1);

	esferaC = new RenderItem(sphere, transformC, colorW);
	esferaX = new RenderItem(sphere, transformX, colorR);
	esferaY = new RenderItem(sphere, transformY, colorG);
	esferaZ = new RenderItem(sphere, transformZ, colorB);

	//Particle* model = new Particle(Vector3D(1, 0, 0), Vector3D(0.2, 0.2, 0.2), 1, 0.999, 0.5, PxVec4(1,0,1,1));
	//model->DeregisterRender(); //Para que la part�cula modelo no se renderice.

	//Distribution* dist = new UniformDistribution(-5, 10);
	//Particularizador particularizador = Particularizador();
	//particularizador.distVelY = dist;
	//particularizador.distVelX = dist;
	//particularizador.distVelZ = dist;

	//ParticleGenerator partGen1 = ParticleGenerator(model, 5.0, particularizador);
	//partSys.AddGenerator(partGen1);

	//ForceGenerator* gravity = new Gravity();
	//partSys.AddForce(gravity);

	//ForceGenerator* torbellin2 = new Wind(Vector3D(-1, 0, 0));
	//ForceGenerator* grav = new Gravity();

	//partSys1->AddForce(torbellin1);
	//partSys2->AddForce(grav);

	//man = GameManager(&rigids, gScene, gPhysics);
	//man.init();


	//4.2 Prueba muelles
	/*
	ParticleSystem* partSys1 = new ParticleSystem(-1, 700.0, Vector3D(0, 0, 0));
	ParticleSystem* partSys2 = new ParticleSystem(-1, 700.0, Vector3D(0, 0, 0));

	Particle* part1 = new Particle(Vector3D(4, 1, 0), Vector3D(0.2, 0.2, 0.2), 1, 0.999, 0.5, PxVec4(0, 1, 1, 1));
	Particle* part2 = new Particle(Vector3D(1, 0, 0), Vector3D(0.2, 0.2, 0.2), 1, 0.999, 0.5, PxVec4(1, 0, 1, 1));

	ForceGenerator* muelle1 = new Muelle(10, part2, 10);
	ForceGenerator* muelle2 = new Muelle(10, part1, 10);
	
	partSys1->AddParticle(part1);
	partSys1->AddForce(muelle1);

	partSys2->AddParticle(part2);
	partSys2->AddForce(muelle2);

	sys.push_back(partSys1);
	sys.push_back(partSys2);
	*/


	//4.2 op Para hacer el slinky
	/*
	Particle* ant = nullptr;
	for (int i = 0; i < 6; i++) {
		ParticleSystem* pSys = new ParticleSystem(-1, 700.0, Vector3D(0, 0, 0));
		Particle* part = new Particle(Vector3D(4, 1 + i * 5, 0), Vector3D(0.2, 0.2, 0.2), 1, 0.999, 0.5, PxVec4(0, 1, 1, 1));
		if (ant != nullptr) {
			ForceGenerator* muelle = new Muelle(1, ant, 1);
			pSys->AddForce(muelle);
		}
		pSys->AddParticle(part);
		sys.push_back(pSys);
		ant = part;
	}
	*/

	//4.3 Flotaci�n
	//Cubo para ver la superficie del agua
	PxRigidStatic* agua = gPhysics->createRigidStatic(PxTransform(0, 33, 0));
	PxShape* shape = CreateShape(PxBoxGeometry(10, 0.1, 10));
	agua->attachShape(*shape);
	gScene->addActor(*agua);
	RenderItem* i = new RenderItem(shape, agua, Vector4(0,0,1,1));

	//Utilizo una part�cula circular en vez de un volumen porque por la arquitectura de mi programa resulta complicado combiar eso
	Particle* part = new Particle(Vector3D(0, 35, 0), Vector3D(0, 0, 0), 0.8, 0.999, 0.5, PxVec4(0, 1, 1, 1));
	ForceGenerator* flotacion = new Flotacion(33, 20, 10);
	ForceGenerator* gravity = new Gravity(); //Le metemos al sistema una fuerza de gravedad para que act�e de forma contraria a la flotaci�n

	ParticleSystem* partSys = new ParticleSystem(-1, 700.0, Vector3D(0, 0, 0));
	partSys->AddForce(flotacion);
	partSys->AddForce(gravity);
	partSys->AddParticle(part);

	sys.push_back(partSys);
}

// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	//man.update(t);
	for (ParticleSystem* s : sys) {
		s->UpdateSystem(t);
	}

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
		//man.Shoot();
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