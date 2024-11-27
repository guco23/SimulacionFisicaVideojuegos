#pragma once
#include <vector>
#include "Vector3D.h"

class Particle;
class ParticleGenerator;
class ForceGenerator;
/*
	Sería mejor que el sistema de particulas conteniense las particulas como tal y gestionase su destrucción
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

	float maxLifetime; //El tiempo de vida máximo posible para las partículas
	float maxDistance; //La distancia máxima para eliminar las partículas
	Vector3D systemPos; //La posición del sistema
	std::vector<Particle*> particles;
};

