#pragma once
#include "ForceGenerator.h"
class Wind :
    public ForceGenerator
{
public:
    Wind(Vector3D);
    virtual void Apply(Particle*) override;
private:
    Vector3D force; //La velocidad del viento
};

