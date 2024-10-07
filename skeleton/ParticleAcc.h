#pragma once
#include "Particle.h"

class ParticleAcc : Particle
{
public:
	ParticleAcc(Vector3D pos, Vector3D vel, Vector3D acc, float damp);
	void integrate(double t) override;
private:
	Vector3D acc;
};