#include "ParticleGenerator.h"
#include "Particle.h"
#include "Distribution.h"

ParticleGenerator::ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate, Particularizador particularizador) : model(model), pos(pos), vel(vel), creationTime(1 / creationrate), elapsedTime(0), particularizador(particularizador) {
	particles = std::vector<Particle*>();
}

void ParticleGenerator::GenerateParticle()
{
	std::unique_ptr<Particle> part = std::make_unique<Particle>(*model);
	//Aleatorizar los atributos de la part�cula.
	TimedParticle tpart = TimedParticle(part, particularizador.timeToDestroy);
	particularizador.Particularizar(tpart, pos, vel);
	particles.push_back(tpart);
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
	for (TimedParticle& tpart : particles) {
		tpart.part->integrate(t);
	}
}

void Particularizador::Particularizar(TimedParticle& tpart, Vector3D pos, Vector3D vel)
{
	//Este m�todo habr�a que hacerlo mucho m�s sofisticado, incluyendo una "forma" sobre la que crea las part�culas.
	//part->setPos(Vector3D(pos.getX() + dist->Generate(), pos.getY() + dist->Generate(), pos.getZ() + dist->Generate()));
	tpart.part->setVel(Vector3D(vel.getX() + dist->Generate(), vel.getY() + dist->Generate(), vel.getZ() + dist->Generate()));
}
