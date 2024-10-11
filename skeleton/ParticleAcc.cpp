#include "ParticleAcc.h"

ParticleAcc::ParticleAcc(Vector3D pos, Vector3D vel, float damp) : Particle(pos, vel, damp) {}

void ParticleAcc::integrate(double t, Vector3D accel) {
	vel = vel + accel * t;
	Particle::integrate(t, accel);
}