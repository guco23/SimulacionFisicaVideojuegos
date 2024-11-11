#pragma once
#include "Distribution.h"

class NormalDistribution : public Distribution
{
public:
	float Generate() override;
	NormalDistribution(float, float);
private:
	std::normal_distribution<float> dist;
};

