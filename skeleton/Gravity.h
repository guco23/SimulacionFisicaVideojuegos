#pragma once
#include "ForceGenerator.h"

class Gravity :
    public ForceGenerator
{
public:
    virtual void Apply(Particle*) override;
};