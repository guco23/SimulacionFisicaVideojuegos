#pragma once
#include "ForceGenerator.h"
class Wind :
    public ForceGenerator
{
public:
    virtual void Apply(Particle*) override;
private:
    Vector3D vel; //La velocidad del viento
};

