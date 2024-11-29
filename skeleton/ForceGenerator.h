#pragma once
#include "Particle.h"

class ParticleSystem;

class ForceGenerator
{
public:
	virtual void Apply(Particle*) = 0;
	void AssignSystem(ParticleSystem*);
protected:
	ParticleSystem* sys;
};