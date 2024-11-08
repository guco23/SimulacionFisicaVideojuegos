#include "UniformDistribution.h"
#include <random>

float UniformDistribution::Generate() {
    return dist(randgen);
}

UniformDistribution::UniformDistribution(float min, float max) : Distribution()
{
    randgen = std::default_random_engine();
    dist = std::uniform_real_distribution<float>(min, max);
}
