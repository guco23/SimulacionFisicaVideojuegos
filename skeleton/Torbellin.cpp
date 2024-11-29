#include "Torbellin.h"
#include "ParticleSystem.h"

Torbellin::Torbellin(float vel) : vel(vel) {}

void Torbellin::Apply(Particle* part)
{
	Vector3D centrVec = part->pos - sys->GetPos();
	centrVec = centrVec * Vector3D(1, 0, 1);
	float distCent = centrVec.Module();
	centrVec.Normalize();
	Vector3D tang = Vector3D(-centrVec.getZ(), 0, centrVec.getX());

	part->accel = part->accel + tang * distCent * vel;
}