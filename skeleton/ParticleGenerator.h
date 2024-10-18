#pragma once
#include "Particle.h"

class ParticleGenerator
{
	/*
		Tendrá una lista en la que meter partículas
		Una partícula modelo a partir de la que crear partículas nuevas
		Posición y velocidad que aplicar a esas partículas
		Un tiempo para crear partículas
		MAS ADELANTE: Un aleatorizador de las partículas
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

