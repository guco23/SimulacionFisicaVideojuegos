#pragma once
#include "Particle.h"

class ParticleGenerator
{
	/*
		Tendr� una lista en la que meter part�culas
		Una part�cula modelo a partir de la que crear part�culas nuevas
		Posici�n y velocidad que aplicar a esas part�culas
		Un tiempo para crear part�culas
		MAS ADELANTE: Un aleatorizador de las part�culas
	*/
public:
	ParticleGenerator(Particle* model, Vector3D pos, Vector3D vel, float creationrate);
	void UpdateGenerator(double, Vector3D acc);
	void CallDelete();
private:
	Particle* model;
	Vector3D pos;
	Vector3D vel;
	float creationTime;
	float elapsedTime;
	std::vector<Particle*> particles;
};

