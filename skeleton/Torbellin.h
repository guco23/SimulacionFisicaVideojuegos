#pragma once
#include "ForceGenerator.h"
class Torbellin :
    public ForceGenerator
{
public:
    Torbellin(float vel);
    virtual void Apply(Particle*) override;
private:
    float vel;
};