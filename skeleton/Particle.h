#pragma once
#include "Vector3D.h"
#include <PxPhysics.h>
#include "RenderUtils.hpp"

//TODO: Refactorizar la herencia de partículas para tener una sóla clase (con todas las funciones)
//Quizás sería interesante cambiar a una arquitectura ECS, dejando sólamente los atributos en partícula

class Particle
{
public:
	Particle(Vector3D pos, Vector3D vel, float masa, float damping, float factVel);
	Particle(const Particle&);
	~Particle();

	virtual Particle* clone() const;

	virtual void integrate(double t);

	void DeregisterRender();

	Vector3D pos;
	Vector3D vel; //La velocidad actual de la partícula
	Vector3D accel; //La aceleración siendo aplicada la partícula, después de aplicar fuerzas.
	float masa;

	float factVel; //factor a la velocidad
	double lifetime;
	float damp; //El factor de damping de la partícula
	float tFact; //El factor de la velocidad de la simulación
private:
	physx::PxTransform pose;
	RenderItem* renderItem;
};