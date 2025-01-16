#include "Flotacion.h"
#include "const.h"

Flotacion::Flotacion(float h, float V, float d) : height(h), volume(V), density(d)
{
	liquidPart = new Particle(Vector3D(0, h, 0), Vector3D(0, 0, 0), 1, 0.9, 1, physx::PxVec4(0, 0, 0, 0));
	liquidPart->DeregisterRender();
}

void Flotacion::Apply(Particle* part)
{
	float h = part->pos.getY();
	float h0 = liquidPart->pos.getY();

	Vector3D f(0, 0, 0);
	float immersed = 0.0;
	if (h - h0 > height * 0.5)
		immersed = 0.0;
	else if (h0 - h > height * 0.5)
		immersed = 1.0;
	else
		immersed = (h0 - h) / height * 0.5;
	f.setY(density * volume * immersed);

	part->fuerza = part->fuerza + f;
}
