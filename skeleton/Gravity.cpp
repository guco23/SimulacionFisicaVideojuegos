#include "Gravity.h"
#include "const.h"
#include "ForceGenerator.h"

void Gravity::Apply(Particle* part)
{
	part->fuerza = part->fuerza + GRAVITY * part->masa;
}
