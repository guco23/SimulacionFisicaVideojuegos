#include "Wind.h"

Wind::Wind(Vector3D vel) : force(vel)
{

}

void Wind::Apply(Particle* part)
{
	part->fuerza = part->fuerza + (force / part->masa);
}