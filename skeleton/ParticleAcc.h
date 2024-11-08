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
	Vector3D accel; //La aceleración siendo aplicada la partícula, después de aplicar fuerzas.
};