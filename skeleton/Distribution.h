#pragma once
#include <random>

class Distribution
{
public:
	virtual float Generate() = 0;
	Distribution();
protected:
	std::default_random_engine randgen;
};