#pragma once
#include "ForceGenerator.h"
class Torbellin :
    public ForceGenerator
{
public:
    Torbellin(float vel, float distance);
    virtual void Apply(Particle*) override;
private:
    float vel;
    //La distnacia m�xima de efecto
    float distance;
};