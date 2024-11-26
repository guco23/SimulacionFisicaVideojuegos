#pragma once
#include "ForceGenerator.h"
class Gravity :
    public ForceGenerator
{
public:
    Gravity();
    virtual void Apply(Particle*) override;
};