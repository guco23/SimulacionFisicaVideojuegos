#pragma once
#include "ParticleAcc.h"
#include "Vector3D.h"

class Proyectil : public ParticleAcc
{
public:
	Proyectil(Vector3D pos, Vector3D vel, float masa, float damping, float factVel);
	Proyectil(const Proyectil&);
	~Proyectil();

	Particle* clone() const override;

	virtual void integrate(double t) override;
private:
	float masa;
	float factVel; //factor a la velocidad
	Vector3D grav;
};