#pragma once
#include "Particle.h"

class ParticleAcc : Particle
{
public:
	ParticleAcc(Vector3D pos, Vector3D vel, float acc);
	void integrate(double t) override;
private:
	float acc;
};