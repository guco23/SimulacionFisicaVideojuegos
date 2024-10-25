#pragma once
#include "Vector3D.h"
#include <PxPhysics.h>
#include "RenderUtils.hpp"
class Particle
{
public:
	Particle(Vector3D pos, Vector3D vel, float damping);
	Particle(const Particle&);
	~Particle();

	virtual Particle* clone() const;

	virtual void integrate(double t, Vector3D accel);
protected:
	Vector3D vel; //La velocidad actual de la partícula
	float damp; //El factor de damping de la partícula

	physx::PxTransform pose;
	RenderItem* renderItem;
};