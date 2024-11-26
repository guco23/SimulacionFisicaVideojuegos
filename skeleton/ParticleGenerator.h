#pragma once
#include "Particle.h"

class Distribution;
class ParticleSystem;

/// <summary>
/// Objeto que contiene las distribuciones para aleatorizar las part�culas de un generador esepc�fico.
/// Debes asignar cada una de las distribuciones que quieres aplicar.
/// El efecto aleatorizador se aplica sobre los valores que ten�a la part�cula en cuanto a velocidad y posici�n.
/// </summary>
struct Particularizador {
	Particularizador() {
		distVelX = nullptr; distPos = nullptr; distVelX = nullptr; distVelY = nullptr; distVelZ = nullptr;
	};
	//Las distribuciones a utilizar para aleatorizar la velocidad y la direcci�n
	Distribution* distVelX;
	Distribution* distVelY;
	Distribution* distVelZ;

	Distribution* distPos;
};

class ParticleGenerator
{

public:
	ParticleGenerator(Particle* model, float creationrate, Particularizador particularizadors);
	friend ParticleSystem;
private:
	Particle* model;
	Vector3D pos;
	Vector3D vel;
	float creationTime;
	float elapsedTime;

	ParticleSystem* mySystem = nullptr;
	Particularizador p;
	void GenerateParticle();

	void UpdateGenerator(double);
	void AssignSystem(ParticleSystem*);
};

