#include "Proyectil.h"
#include "const.h"

Proyectil::Proyectil(Vector3D pos, Vector3D vel, Vector3D acc, float masa, float damping) : ParticleAcc(pos, vel, acc, damping), masa(masa) {

}

void Proyectil::integrate(double t) {
	acc = acc + Vector3D(0, GRAVITY * t, 0) * masa;
	
	ParticleAcc::integrate(t);
}

//gr simulada =  vsimulada^2 / vreal^2