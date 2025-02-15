#include "ParticleSystem.h"
#include "Particle.h"
#include "ParticleGenerator.h"
#include "ForceGenerator.h"

ParticleSystem::ParticleSystem(float maxLifetime, float maxDistance, Vector3D systemPos) : maxLifetime(maxLifetime), maxDistance(maxDistance), systemPos(systemPos)
{
	particles = std::vector<Particle*>();
	generators = std::vector<ParticleGenerator>();
	forces = std::vector<ForceGenerator*>();
}

void ParticleSystem::AddGenerator(ParticleGenerator& generator)
{
	generator.AssignSystem(this);
	generators.push_back(generator);
}

void ParticleSystem::AddForce(ForceGenerator* force)
{
	force->AssignSystem(this);
	forces.push_back(force);
}

void ParticleSystem::UpdateSystem(double t)
{
	for (ParticleGenerator& generator : generators) {
		generator.UpdateGenerator(t);
	}

	//La eliminación de las partículas
	for (std::vector<Particle*>::iterator iter = particles.begin(); iter != particles.end();) {
		Particle* part = *iter;

		for (ForceGenerator* force : forces)
			force->Apply(part);

		part->integrate(t);

		//Comprobar destrucciones
		if (part->lifetime > maxLifetime && maxLifetime != -1 //Si la particula no tiene deletiontime no se elimina
			|| (part->pos - systemPos).Module() > maxDistance) {
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

ParticleSystem::~ParticleSystem()
{
	for (auto i : forces) {
		delete i;
	}
	for (auto i : particles) {
		delete i;
	}
}
