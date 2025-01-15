#include "Muelle.h"

Muelle::Muelle(double k, Particle* anc, double l)
{
	this->k = k;
	this->anc = anc;
	this->length = l;
}

void Muelle::Apply(Particle* part)
{
	Vector3D vector = anc->pos - part->pos;

	const float vlength = vector.Module();
	vector.Normalize();

	const float delta = vlength - length;

	part->fuerza = part->fuerza + (vector * delta * k);
}