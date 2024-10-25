#include "ParticleAcc.h"

ParticleAcc::ParticleAcc(Vector3D pos, Vector3D vel, float damp) : Particle(pos, vel, damp) {}

ParticleAcc::ParticleAcc(const ParticleAcc& partAcc) : Particle(partAcc) {}

Particle* ParticleAcc::clone() const
{
	return new ParticleAcc(*this);
}

void ParticleAcc::integrate(double t, Vector3D accel) {
	vel = vel + accel * t;
	Particle::integrate(t, accel);
}