#pragma once
#include "ParticleAcc.h"
#include "Vector3D.h"

class Proyectil : public ParticleAcc
{
public:
	Proyectil(Vector3D pos, Vector3D vel, float masa, float damping, float factVel);
	~Proyectil();

	virtual void integrate(double t, Vector3D accel) override;
private:
	float masa;
	float factVel; //factor a la velocidad
	Vector3D grav;
};