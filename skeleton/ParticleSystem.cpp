#include "ParticleSystem.h"
#include "Particle.h"
#include "ParticleGenerator.h"

ParticleSystem::ParticleSystem(float maxLifetime, float maxDistance, Vector3D systemPos) : maxLifetime(maxLifetime), maxDistance(maxDistance), systemPos(systemPos)
{
	particles = std::vector<Particle*>();
	generators = std::vector<ParticleGenerator>();
}

void ParticleSystem::AddGenerator(ParticleGenerator& generator)
{
	generator.AssignSystem(this);
	generators.push_back(generator);
}

void ParticleSystem::UpdateSystem(double t)
{
	for (ParticleGenerator& generator : generators) {
		generator.UpdateGenerator(t);
	}
	//Actualizar todas las particulas

	//La eliminación de las partículas
	for (std::vector<Particle*>::iterator iter = particles.begin(); iter != particles.end();) {
		Particle* part = *iter;
		part->integrate(t);

		//Comprobar destrucciones
		if (part->getLifetime() > maxLifetime || (part->getPos() - systemPos).Module() > maxDistance) {
			delete part;
			iter = particles.erase(iter);
		}
		else {
			++iter;
		}
	}
}

void ParticleSystem::AddParticle(Particle* part)
{
	particles.push_back(part);
}

Vector3D ParticleSystem::GetPos()
{
	return systemPos;
}
