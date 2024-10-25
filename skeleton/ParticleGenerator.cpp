#include "ParticleGenerator.h"
#include "Particle.h"

ParticleGenerator::ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate) : model(model), pos(pos), vel(vel), creationTime(1 / creationrate), elapsedTime(0) {
	particles = std::vector<Particle*>();
}

void ParticleGenerator::CallDelete()
{
	for (Particle* part : particles)
		delete part;
}

void ParticleGenerator::UpdateGenerator(double t, Vector3D acc)
{
	/*
		Actualizar el tiempo para generar y generar particula si se cumple
	*/
	elapsedTime += t;
	if (elapsedTime > creationTime) {
		Particle* part = model->clone();
		particles.push_back(part);
		elapsedTime = 0;
	}
	for (Particle* part : particles) {
		part->integrate(t, acc);
	}
}