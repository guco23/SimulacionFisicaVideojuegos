#include "ParticleGenerator.h"
#include "Particle.h"
#include "Distribution.h"

ParticleGenerator::ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate, float maxLifetime, float maxDistance, Particularizador particularizador) : model(model), pos(pos), vel(vel), creationTime(1 / creationrate), elapsedTime(0), maxLifetime(maxLifetime), maxDistance(maxDistance), p(particularizador) {
	particles = std::vector<Particle>();
}

void ParticleGenerator::GenerateParticle()
{
	//Aleatorizar los atributos de la partícula.
	Particle part = Particle(*model);

	if(p.distPos != nullptr)
		part.setPos(part.getPos() + Vector3D(p.distPos->Generate(), p.distPos->Generate(), p.distPos->Generate()));
	if (p.distVel != nullptr)
		part.setVel(part.getVel() * p.distVel->Generate());
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

Particularizador::Particularizador(Distribution* distVel = nullptr, Distribution* distPos = nullptr) : distVel(distVel), distPos(distPos) {}