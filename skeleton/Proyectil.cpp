#include "Proyectil.h"
#include "const.h"

Proyectil::Proyectil(Vector3D pos, Vector3D vel, float masa, float damping, float factVel) : ParticleAcc(pos, vel, damping), masa(masa), factVel(factVel) {
	this->vel = vel * factVel;
	this->masa = masa / (factVel * factVel);
	this->grav = GRAVITY * (this->vel.DotProduct(this->vel) / vel.DotProduct(vel));
}

void Proyectil::integrate(double t, Vector3D accel) {
	accel = accel + grav;
	ParticleAcc::integrate(t, accel);
}

//gr simulada =  vsimulada^2 / vreal^2 * gr real