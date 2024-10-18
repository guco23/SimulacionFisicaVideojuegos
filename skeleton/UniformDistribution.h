#pragma once
#include "Distribution.h"
#include <random>

class UniformDistribution : public Distribution
{
public:
	virtual float Generate() const override;
	UniformDistribution(float min, float max);
private:
	std::uniform_real_distribution<> dist;
};