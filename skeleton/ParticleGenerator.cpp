#include "ParticleGenerator.h"
#include "Particle.h"
#include "Distribution.h"

ParticleGenerator::ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate) : model(model), pos(pos), vel(vel), creationTime(1 / creationrate), elapsedTime(0) {
	particles = std::vector<Particle>();
}

void ParticleGenerator::GenerateParticle()
{
	//Aleatorizar los atributos de la partícula.
	Particle part = Particle(*model);
	particles.push_back(part);
}

void ParticleGenerator::UpdateGenerator(double t)
{
	/*
		Actualizar el tiempo para generar y generar particula si se cumple
	*/
	elapsedTime += t;
	if (elapsedTime > creationTime) {
		GenerateParticle();
		elapsedTime = 0;
	}
	for (Particle& part : particles) {
		part.integrate(t);
	}
}