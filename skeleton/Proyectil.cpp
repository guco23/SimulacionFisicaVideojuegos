#include "Proyectil.h"
#include "const.h"

Proyectil::Proyectil(Vector3D pos, Vector3D vel, float masa, float damping, float factVel) : ParticleAcc(pos, vel, damping), masa(masa), factVel(factVel) {
	this->vel = vel * factVel;
	this->masa = masa / (factVel * factVel);
	this->grav = GRAVITY * (this->vel.DotProduct(this->vel) / vel.DotProduct(vel));
}

Proyectil::Proyectil(const Proyectil& proy) : ParticleAcc(proy), masa(proy.masa), factVel(factVel)
{
	vel = proy.vel;
	masa = proy.masa;
	grav = proy.grav;
}

Particle* Proyectil::clone() const
{
	return new Proyectil(*this);
}

void Proyectil::integrate(double t) {
	accel = accel + grav;
	ParticleAcc::integrate(t);
}

//gr simulada =  vsimulada^2 / vreal^2 * gr real