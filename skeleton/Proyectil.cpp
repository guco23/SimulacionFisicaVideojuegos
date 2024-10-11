#include "Proyectil.h"
#include "const.h"

Proyectil::Proyectil(Vector3D pos, Vector3D vel, Vector3D acc, float masa, float damping) : ParticleAcc(pos, vel, acc, damping), masa(masa) {

}

void Proyectil::integrate(double t) {
	ParticleAcc::integrate(t);
	vel = vel + Vector3D(0, GRAVITY, 0) * masa;
}