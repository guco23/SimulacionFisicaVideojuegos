#include "Proyectil.h"
Proyectil::Proyectil(Vector3D pos, Vector3D vel, Vector3D acc, float masa, float damping) : ParticleAcc(pos, vel, acc, damping) {

}

void Proyectil::integrate(double t) {

}