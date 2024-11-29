#pragma once
#include "Vector3D.h"
#include <PxPhysics.h>
#include "RenderUtils.hpp"

//TODO: Refactorizar la herencia de part�culas para tener una s�la clase (con todas las funciones)
//Quiz�s ser�a interesante cambiar a una arquitectura ECS, dejando s�lamente los atributos en part�cula

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
	Vector3D vel; //La velocidad actual de la part�cula
	Vector3D accel; //La aceleraci�n siendo aplicada la part�cula, despu�s de aplicar fuerzas.
	float masa;

	float factVel; //factor a la velocidad
	double lifetime;
	float damp; //El factor de damping de la part�cula
	float tFact; //El factor de la velocidad de la simulaci�n
private:
	physx::PxTransform pose;
	RenderItem* renderItem;
};