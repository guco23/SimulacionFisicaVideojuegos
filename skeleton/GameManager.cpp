#include "GameManager.h"
#include "ParticleGenerator.h"
#include "RigidBody.h"
#include <iostream>

void GameManager::SetRound()
{
	switch (round) {
	case 0:
		goal = new RigidBody(Vector3D(0,10,0), CreateShape(PxBoxGeometry(5, 5, 5)), scene, phys, { 0,1,0,1 }, false);
		break;
	}
}

void GameManager::CollisionDetected(PxActor* actor1, PxActor* actor2)
{
	//Condición de victoria
	if (goal->CheckActor(actor1) || goal->CheckActor(actor2)) {
		Won();
	}
}

GameManager::GameManager(ParticleSystem* ps, std::list<RigidBody*>* rbs, PxScene* scene, PxPhysics* phys) : rigids(rbs), partSys(ps), scene(scene), phys(phys)
{
	points = 0;
	round = 0;
	shootForce = 500;
}

void GameManager::Won()
{
	std::cout << "vvvvvv";
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
