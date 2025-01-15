#pragma once
#include "ForceGenerator.h"
class Muelle : public ForceGenerator
{
public:
	Muelle(double k, Particle* anc, double lenght);

	virtual void Apply(Particle*) override;
protected:
	double length;
	double k;
	Particle* anc;
};

