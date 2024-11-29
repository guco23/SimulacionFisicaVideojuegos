#include "ParticleGenerator.h"
#include "Particle.h"
#include "Distribution.h"
#include "ParticleSystem.h"

ParticleGenerator::ParticleGenerator(Particle* model, float creationrate, Particularizador particularizador) : model(model), pos(pos), vel(vel), creationTime(1 / creationrate), elapsedTime(0), p(particularizador) {}

void ParticleGenerator::GenerateParticle()
{
	//Aleatorizar los atributos de la partícula.
	Particle* part = new Particle(*model);

	if(p.distPos)
		part->pos = part->pos + mySystem->GetPos() + Vector3D(p.distPos->Generate(), p.distPos->Generate(), p.distPos->Generate());
	if (p.distVelX) {
		part->vel = part->vel + Vector3D(p.distVelX->Generate(),0,0);
	}
	if (p.distVelY) {
		part->vel = part->vel + Vector3D(0, p.distVelY->Generate(), 0);
	}
	if (p.distVelZ) {
		part->vel = part->vel + Vector3D(0, 0, p.distVelZ->Generate());
	}
	mySystem->AddParticle(part);
	
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

}

void ParticleGenerator::AssignSystem(ParticleSystem* syst)
{
	mySystem = syst;
}

