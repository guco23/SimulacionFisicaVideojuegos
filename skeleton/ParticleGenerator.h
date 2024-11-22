#pragma once
#include "Particle.h"

class Distribution;


struct Particularizador {
	Particularizador(Distribution* distVel, Distribution* distPos);
	Particularizador() { distVel = nullptr; distPos = nullptr; };
	//Las distribuciones a utilizar para aleatorizar la velocidad y la dirección
	Distribution* distVel;
	Distribution* distPos;
};

class ParticleGenerator
{

public:
	ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate, float maxLifetime, float maxDistance, Particularizador particularizadors);
	void UpdateGenerator(double);
private:
	Particle* model;
	Vector3D pos;
	Vector3D vel;
	float creationTime;
	float elapsedTime;
	float maxLifetime;
	float maxDistance;
	std::vector<Particle*> particles;

	Particularizador p;
	void GenerateParticle();
};

