#pragma once
#include "ForceGenerator.h"

class Flotacion : public ForceGenerator
{
public:
	Flotacion(float h, float V, float d);

	virtual void Apply(Particle*) override;
protected:
	float height;
	float volume;
	float density;

	Particle* liquidPart;
};