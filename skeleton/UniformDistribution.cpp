#include "UniformDistribution.h"
#include <random>

float UniformDistribution::Generate() const
{
    //return dist(randgen);
    return 1.0;
}

UniformDistribution::UniformDistribution(float min, float max) : Distribution()
{
    dist = std::uniform_real_distribution<>(min, max);
}
