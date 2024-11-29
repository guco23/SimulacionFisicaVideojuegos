#include "Wind.h"

Wind::Wind(Vector3D vel) : force(vel)
{

}

void Wind::Apply(Particle* part)
{
	part->accel = part->accel + (force / part->masa);
}