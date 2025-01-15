#include "GameManager.h"
#include "ParticleGenerator.h"
#include "RigidBody.h"
#include <iostream>
#include "UniformDistribution.h"
#include "Gravity.h"
#include "Torbellin.h"
#include "Wind.h"

void GameManager::SetRound()
{
	roundEnded = false;
	//Eliminamos todas las particulas y solidos
	for (ParticleSystem* ps : partSysL) {
		delete ps;
	}
	partSysL.clear();
	//Creamos la nueva ronda
	switch (round) {
	case 0:
		goals.push_back(new RigidBody(Vector3D(0,10,0), CreateShape(PxBoxGeometry(5, 5, 5)), scene, phys, { 0,1,0,1 }, false));
		numTargets = 1;
		break;
	case 1:
		goals.push_back(new RigidBody(Vector3D(0, 100, 0), CreateShape(PxBoxGeometry(5, 5, 5)), scene, phys, { 0,1,0,1 }, false));
		numTargets = 1;
		break;
	case 2:
		goals.push_back(new RigidBody(Vector3D(100, 40, 0), CreateShape(PxBoxGeometry(5, 5, 5)), scene, phys, {0,1,0,1}, false));
		goals.push_back(new RigidBody(Vector3D(80, 90, 2), CreateShape(PxBoxGeometry(5, 5, 5)), scene, phys, { 0,1,0,1 }, false));

		numTargets = 2;

		break;
	case 3:
		goals.push_back(new RigidBody(Vector3D(10, 60, 60), CreateShape(PxBoxGeometry(5, 5, 5)), scene, phys, { 0,1,0,1 }, false));
		goals.push_back(new RigidBody(Vector3D(100, 40, 0), CreateShape(PxBoxGeometry(5, 5, 5)), scene, phys, { 0,1,0,1 }, false));
		goals.push_back(new RigidBody(Vector3D(150, 50, 50), CreateShape(PxBoxGeometry(5, 5, 5)), scene, phys, { 0,1,0,1 }, false));

		numTargets = 3;

		break;
	}
}

void GameManager::CreateCelebrationParticles(Vector3D pos)
{
	ParticleSystem* partSys = new ParticleSystem(20.0, 30.0, pos);
	Particle* model = new Particle(Vector3D(0, 0, 0), Vector3D(0.2, 0.2, 0.2), -0.1, 0.999, 0.5, physx::PxVec4(0,1,0,1));
	model->DeregisterRender(); //Para que la partícula modelo no se renderice.

	Distribution* dist = new UniformDistribution(-16, 16);
	Particularizador particularizador = Particularizador();
	particularizador.distVelY = dist;
	particularizador.distVelX = dist;
	particularizador.distVelZ = dist;

	ParticleGenerator partGen1 = ParticleGenerator(model, 50.0, particularizador);
	partSys->AddGenerator(partGen1);

	if (points == 0) {
		ForceGenerator* gravity = new Gravity();
		partSys->AddForce(gravity);
	}
	else if (points == 1) {
		ForceGenerator* torbellin = new Torbellin(1.1, 30);
		partSys->AddForce(torbellin);
	}
	else if (points == 2) {
		ForceGenerator* wind = new Wind(Vector3D(0,2,1));
		partSys->AddForce(wind);
	}

	partSysL.push_back(partSys);
}

void GameManager::CollisionDetected(PxActor* actor1, PxActor* actor2)
{
	//Condición de victoria
	for (RigidBody* goal : goals) {
		if (goal->CheckActor(actor1) || goal->CheckActor(actor2)) {
			Hit(goal);
			return;
		}
	}
}

GameManager::GameManager(std::list<RigidBody*>* rbs, PxScene* scene, PxPhysics* phys) : rigids(rbs), scene(scene), phys(phys)
{
	points = 0;
	round = 0;
	shootForce = 500;
	overtimeTimer = 0;
}

void GameManager::Hit(RigidBody* goal)
{
	CreateCelebrationParticles(goal->GetPosition());
	goals.remove(goal);
	delete goal;
	points++;
	if (points >= numTargets) {
		roundEnded = true;
		points = 0;
	}
}

void GameManager::Shoot()
{
	//partSys->AddParticle(new Particle(Vector3D(GetCamera()->getEye().x, GetCamera()->getEye().y, GetCamera()->getEye().z),
	//	Vector3D(-GetCamera()->getDir().x, -GetCamera()->getDir().y, -GetCamera()->getDir().z),
	//	1, 0.999, 0.5));

	RigidBody* bullet = new RigidBody(Vector3D(GetCamera()->getEye().x, GetCamera()->getEye().y, GetCamera()->getEye().z),
		CreateShape(PxBoxGeometry(3, 3, 3)), scene, phys , { 1,0,1,1 }, true);
	bullet->SetMass(0.1);
	bullet->AddForce(Vector3D(GetCamera()->getDir().x, GetCamera()->getDir().y, GetCamera()->getDir().z) * shootForce);
	rigids->push_back(bullet);
}

void GameManager::init()
{
	SetRound();
}

void GameManager::update(double t)
{
	if (roundEnded) {
		overtimeTimer += t;
		if (overtimeTimer >= 2) {
			round++;
			SetRound();
			overtimeTimer = 0;
		}
	}
	for (ParticleSystem* partSys : partSysL) {
		partSys->UpdateSystem(t);
	}
}
