#pragma once
#include "Particle.h"

class Distribution;
class ParticleGenerator
{
	/*
		Tendrá una lista en la que meter partículas
		Una partícula modelo a partir de la que crear partículas nuevas
		Posición y velocidad que aplicar a esas partículas
		Un tiempo para crear partículas
		MAS ADELANTE: Un aleatorizador de las partículas
	*/
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
	};

public:
	ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate, Particularizador particularizador);
	void UpdateGenerator(double, Vector3D acc);
	void CallDelete();
private:
	Particle* model;
	Vector3D pos;
	Vector3D vel;
	float creationTime;
	float elapsedTime;
	std::vector<Particle*> particles;
	Particularizador particularizador
};

