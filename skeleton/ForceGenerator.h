#pragma once
#include "Particle.h"

class ForceGenerator
{
public:
	virtual void Apply(Particle*) = 0;
};