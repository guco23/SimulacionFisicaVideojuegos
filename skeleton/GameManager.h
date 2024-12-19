#pragma once
#include "ParticleSystem.h"
#include <map>
#include <string>
#include "RigidBody.h"
#include <list>

class GameManager
{
private:
	int points;
	int round;
	float shootForce;
	void SetRound();
	ParticleSystem* partSys;
	std::list<RigidBody*>* rigids;
	PxScene* scene; PxPhysics* phys;

	RigidBody* goal = nullptr;
public:
	void CollisionDetected(PxActor*, PxActor*);
	GameManager(ParticleSystem*, std::list<RigidBody*>*, PxScene* scene, PxPhysics* phys);
	GameManager() {};
	void Won();
	void Lost();
	void Shoot();
	void init();
};

