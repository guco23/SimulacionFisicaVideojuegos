#include "Torbellin.h"
#include "ParticleSystem.h"
#include "ParticleGenerator.h"

Torbellin::Torbellin(float vel) : vel(vel) {}

void Torbellin::Apply(Particle* part)
{
	Vector3D centrVec = part->pos - sys->GetPos();
	Vector3D fuerza = Vector3D(-centrVec.getZ(), 0, centrVec.getX());
	//fuerza = fuerza - centrVec * 1 / vel;

	part->accel = part->accel + fuerza * vel;
}