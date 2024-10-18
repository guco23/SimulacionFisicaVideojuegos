#include "ParticleSystem.h"
#include "Particle.h"
#include "ParticleGenerator.h"

ParticleSystem::ParticleSystem()
{

}

void ParticleSystem::AddGenerator(ParticleGenerator generator)
{
	generators.push_back(generator);
}

void ParticleSystem::UpdateSystem(double t, Vector3D acc)
{
	for (ParticleGenerator& generator : generators) {
		generator.UpdateGenerator(t);
	}
	for (Particle* part : particles) {
		part->integrate(t, acc);
	}
}
