#pragma once
#include "Particle.h"

class ParticleAcc : public Particle
{
public:
	ParticleAcc(Vector3D pos, Vector3D vel, Vector3D acc, float damp);
	virtual void integrate(double t) override;
protected:
	Vector3D acc;
};