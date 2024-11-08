#include "ParticleAcc.h"

ParticleAcc::ParticleAcc(Vector3D pos, Vector3D vel, float damp) : Particle(pos, vel, damp) {
	accel = Vector3D(0,0,0);
}

ParticleAcc::ParticleAcc(const ParticleAcc& partAcc) : Particle(partAcc) {
	accel = Vector3D(0, 0, 0);
}

Particle* ParticleAcc::clone() const
{
	return new ParticleAcc(*this);
}

void ParticleAcc::integrate(double t) {
	vel = vel + accel * t;
	Particle::integrate(t);
}