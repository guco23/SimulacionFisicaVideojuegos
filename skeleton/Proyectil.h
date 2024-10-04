#pragma once
#include "Particle.h"
#include "Vector3D.h"

class Proyectil : Particle
{
public:
	Proyectil(Vector3D pos, Vector3D vel, float masa, float damping);
	~Proyectil();

	void integrate(double t) override;
private:
	float mass;
};