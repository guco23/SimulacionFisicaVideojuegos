#include "ParticleGenerator.h"
#include "Particle.h"
#include "Distribution.h"

ParticleGenerator::ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate, Particularizador particularizador) : model(model), pos(pos), vel(vel), creationTime(1 / creationrate), elapsedTime(0), particularizador(particularizador) {
	particles = std::vector<Particle*>();
}

void ParticleGenerator::CallDelete()
{
	for (Particle* part : particles)
		delete part;
}

void ParticleGenerator::GenerateParticle()
{
	Particle* part = new Particle(*model);
	//Aleatorizar los atributos de la partícula.
	particularizador.Particularizar(part, pos, vel);
	particles.push_back(part);
	elapsedTime = 0;
}

void ParticleGenerator::UpdateGenerator(double t)
{
	/*
		Actualizar el tiempo para generar y generar particula si se cumple
	*/
	elapsedTime += t;
	if (elapsedTime > creationTime) {
		GenerateParticle();
	}
	for (Particle* part : particles) {
		part->integrate(t);
	}
}

void Particularizador::Particularizar(Particle* part, Vector3D pos, Vector3D vel)
{
	//Este método habría que hacerlo mucho más sofisticado, incluyendo una "forma" sobre la que crea las partículas.
	part->setPos(Vector3D(pos.getX() + dist->Generate(), pos.getY() + dist->Generate(), pos.getZ() + dist->Generate()));
	part->setVel(Vector3D(vel.getX() + dist->Generate(), vel.getY() + dist->Generate(), vel.getZ() + dist->Generate()));
}
