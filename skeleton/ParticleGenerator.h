#pragma once
#include "Particle.h"

class Distribution;

struct Particularizador {
public:
	Particularizador(
		Distribution* dist = nullptr, bool destOnPos = false, bool destOnTime = false, float destroyDistance = 0, float timeToDestroy = 0) :
		dist(dist), destroyOnPos(destOnPos), destroyOnTime(destOnTime), destroyDistance(destroyDistance), timeToDestroy(timeToDestroy) {};
	Distribution* dist;
	bool destroyOnPos;
	bool destroyOnTime;
	float destroyDistance;
	float timeToDestroy;

	void Particularizar(TimedParticle& part, Vector3D(pos), Vector3D(vel));
};

struct TimedParticle {
public:
	TimedParticle(std::unique_ptr<Particle> part, float lifeTime) : part(std::move(part)), lifeTime(lifeTime) {};
	std::unique_ptr<Particle> part;
	float lifeTime;
};

class ParticleGenerator
{

public:
	ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate, Particularizador particularizador);
	void UpdateGenerator(double);
private:
	Particle* model;
	Vector3D pos;
	Vector3D vel;
	float creationTime;
	float elapsedTime;
	std::vector<TimedParticle> particles;
	Particularizador particularizador;

	void GenerateParticle();
};

