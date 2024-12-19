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
	std::list<ParticleSystem*> partSysL;

	std::list<RigidBody*>* rigids;
	PxScene* scene; PxPhysics* phys;
	double overtimeTimer;
	bool roundEnded;
	int numTargets;

	void CreateCelebrationParticles(Vector3D);
	std::list<RigidBody*> goals;
public:
	void CollisionDetected(PxActor*, PxActor*);
	GameManager(std::list<RigidBody*>*, PxScene* scene, PxPhysics* phys);
	GameManager() {};
	void Hit(RigidBody*);
	void Lost();
	void Shoot();
	void init();
	void update(double t);
	
};

