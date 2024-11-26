#include "Gravity.h"
#include "const.h"

void Gravity::Apply(Particle* part)
{
	part->accel = part->accel + GRAVITY * part->tFact;
}
