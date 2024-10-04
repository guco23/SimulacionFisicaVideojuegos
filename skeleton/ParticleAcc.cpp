#include "ParticleAcc.h"

ParticleAcc::ParticleAcc(Vector3D pos, Vector3D vel, float acc, float damp) : Particle(pos, vel, damp), acc(acc) {}

void ParticleAcc::integrate(double t) {
	vel.Scale(acc);
	Particle::integrate(t);
}