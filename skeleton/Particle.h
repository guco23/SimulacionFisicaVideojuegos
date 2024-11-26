#pragma once
#include "Vector3D.h"
#include <PxPhysics.h>
#include "RenderUtils.hpp"

//TODO: Refactorizar la herencia de part�culas para tener una s�la clase (con todas las funciones)
//Quiz�s ser�a interesante cambiar a una arquitectura ECS, dejando s�lamente los atributos en part�cula

class Particle
{
public:
	friend class Gravity;

	Particle(Vector3D pos, Vector3D vel, float masa, float damping, float factVel);
	Particle(const Particle&);
	~Particle();

	virtual Particle* clone() const;

	virtual void integrate(double t);

	void DeregisterRender();

	void setPos(Vector3D);
	void setVel(Vector3D);
	Vector3D getPos() const;
	Vector3D getVel() const;
	double getLifetime() const;
protected:
	Vector3D vel; //La velocidad actual de la part�cula
	float damp; //El factor de damping de la part�cula
	Vector3D accel; //La aceleraci�n siendo aplicada la part�cula, despu�s de aplicar fuerzas.
	float masa;
	float factVel; //factor a la velocidad
	Vector3D grav; //Esto se va a ir ya que la gravedad ser� una fuerza en el sistema
	double lifetime;

	float tFact; //El factor de la velocidad de la simulaci�n

	physx::PxTransform pose;

	RenderItem* renderItem;
};