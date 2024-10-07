#pragma once
#include "ParticleAcc.h"
#include "Vector3D.h"

class Proyectil : public ParticleAcc
{
public:
	Proyectil(Vector3D pos, Vector3D vel, Vector3D acc, float masa, float damping);
	~Proyectil();

	void integrate(double t) override;
};