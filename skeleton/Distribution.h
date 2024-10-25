#pragma once
#include <random>

class Distribution
{
public:
	virtual float Generate() const = 0;
	Distribution();
protected:
	std::mt19937 randgen;
};