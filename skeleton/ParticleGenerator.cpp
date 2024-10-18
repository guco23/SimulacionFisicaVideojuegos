#include "ParticleGenerator.h"

ParticleGenerator::ParticleGenerator(Particle model, Vector3D pos, Vector3D vel, float creationrate, std::vector<Particle>& particles) : model(model), pos(pos), vel(vel), creationTime(1 / creationrate), particles(particles) {}

void ParticleGenerator::UpdateGenerator(double t)
{
	/*
		Actualizar el tiempo para generar y generar particula si se cumple
	*/
}
