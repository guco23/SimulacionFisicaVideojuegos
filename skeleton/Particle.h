#pragma once
#include "Vector3D.h"
#include <PxPhysics.h>
#include "RenderUtils.hpp"
class Particle
{
public:
	Particle(Vector3D pos, Vector3D vel);
	~Particle();

	void integrate(double t);
private:
	Vector3D vel;
	physx::PxTransform pose;
	RenderItem* renderItem;
};