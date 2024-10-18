#pragma once
#include <vector>
#include "Vector3D.h"

class Particle;
class ParticleGenerator;

class ParticleSystem
{
public:
	ParticleSystem();
	void AddGenerator(ParticleGenerator&);
	void UpdateSystem(double t, Vector3D acc);
	void CallDelete();
private:
	std::vector<ParticleGenerator> generators;
};

