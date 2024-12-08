#include "Torbellin.h"
#include "ParticleSystem.h"
#include "ParticleGenerator.h"

Torbellin::Torbellin(float vel, float dis) : vel(vel), distance(dis) {}

void Torbellin::Apply(Particle* part)
{
	Vector3D centrVec = part->pos - sys->GetPos();
	Vector3D fuerza = Vector3D(-centrVec.getZ(), 0, centrVec.getX());
	//fuerza = fuerza - centrVec * 1 / vel;

	if (fuerza.Module() < distance)
		part->fuerza = part->fuerza + fuerza / part->masa * vel;
}