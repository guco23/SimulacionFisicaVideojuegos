#include "NormalDistribution.h"
#include <random>

float NormalDistribution::Generate()
{
	return dist(randgen);
}

NormalDistribution::NormalDistribution(float mean, float diff)
{
	randgen = std::default_random_engine();
	dist = std::normal_distribution<float>(mean, diff);
}
