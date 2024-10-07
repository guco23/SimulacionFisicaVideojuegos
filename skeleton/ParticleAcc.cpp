#include "ParticleAcc.h"

ParticleAcc::ParticleAcc(Vector3D pos, Vector3D vel, Vector3D acc, float damp) : Particle(pos, vel, damp), acc(acc) {}

void ParticleAcc::integrate(double t) {
	vel = vel + acc * t;
	Particle::integrate(t);
}