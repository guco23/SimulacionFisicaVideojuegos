#pragma once
#include "Particle.h"

class Distribution;

class ParticleGenerator
{

public:
	ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate);
	void UpdateGenerator(double);
private:
	Particle* model;
	Vector3D pos;
	Vector3D vel;
	float creationTime;
	float elapsedTime;
	std::vector<Particle> particles;

	void GenerateParticle();
};

