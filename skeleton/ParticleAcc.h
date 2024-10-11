#pragma once
#include "Particle.h"

class ParticleAcc : public Particle
{
public:
	ParticleAcc(Vector3D pos, Vector3D vel, float damp);
	virtual void integrate(double t, Vector3D accel) override;
};