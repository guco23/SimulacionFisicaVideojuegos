#include "ParticleSystem.h"
#include "Particle.h"
#include "ParticleGenerator.h"

ParticleSystem::ParticleSystem()
{
	generators = std::vector<ParticleGenerator>();
}

void ParticleSystem::AddGenerator(ParticleGenerator& generator)
{
	generators.push_back(generator);
}

void ParticleSystem::UpdateSystem(double t)
{
	for (ParticleGenerator& generator : generators) {
		generator.UpdateGenerator(t);
	}
}

void ParticleSystem::CallDelete()
{
	for (ParticleGenerator& generator : generators) {
		generator.CallDelete();
	}
}
