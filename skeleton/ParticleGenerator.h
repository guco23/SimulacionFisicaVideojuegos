#pragma once
#include "Particle.h"

class Distribution;
class ParticleGenerator
{
	/*
		Tendr� una lista en la que meter part�culas
		Una part�cula modelo a partir de la que crear part�culas nuevas
		Posici�n y velocidad que aplicar a esas part�culas
		Un tiempo para crear part�culas
		MAS ADELANTE: Un aleatorizador de las part�culas
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

