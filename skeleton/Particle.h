#pragma once
#include "Vector3D.h"
#include <PxPhysics.h>
#include "RenderUtils.hpp"
class Particle
{
public:
	Particle(Vector3D pos, Vector3D vel, float damping);
	~Particle();

	virtual void integrate(double t);
protected:
	Vector3D vel; //La velocidad actual de la part�cula
	float damp; //El factor de damping de la part�cula

	physx::PxTransform pose;
	RenderItem* renderItem;
};