#pragma once
#include "Particle.h"

class ParticleAcc : public Particle
{
public:
	ParticleAcc(Vector3D pos, Vector3D vel, float damp);
	virtual void integrate(double t) override;
	ParticleAcc(const ParticleAcc&);

	virtual Particle* clone() const override;
protected:
	Vector3D accel; //La aceleraci�n siendo aplicada la part�cula, despu�s de aplicar fuerzas.
};