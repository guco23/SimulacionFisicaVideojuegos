#pragma once
#include <vector>
#include "Vector3D.h"

class Particle;
class ParticleGenerator;
class ForceGenerator;
/*
	Ser�a mejor que el sistema de particulas conteniense las particulas como tal y gestionase su destrucci�n
*/
class ParticleSystem
{
public:
	ParticleSystem(float maxLifetime, float maxDistance, Vector3D systemPos);
	ParticleSystem() {}; //cambiar esto
	void AddGenerator(ParticleGenerator&);
	void AddForce(ForceGenerator*);
	void UpdateSystem(double t);

	void AddParticle(Particle* part);
	Vector3D GetPos();

	~ParticleSystem();
private:
	std::vector<ParticleGenerator> generators;
	std::vector<ForceGenerator*> forces;

	float maxLifetime; //El tiempo de vida m�ximo posible para las part�culas
	float maxDistance; //La distancia m�xima para eliminar las part�culas
	Vector3D systemPos; //La posici�n del sistema
	std::vector<Particle*> particles;
};

