#pragma once
#include <vector>
#include "Vector3D.h"

class Particle;
class ParticleGenerator;

/*
	Sería mejor que el sistema de particulas conteniense las particulas como tal y gestionase su destrucción
*/
class ParticleSystem
{
public:
	ParticleSystem();
	void AddGenerator(ParticleGenerator&);
	void UpdateSystem(double t);
private:
	std::vector<ParticleGenerator> generators;
};

