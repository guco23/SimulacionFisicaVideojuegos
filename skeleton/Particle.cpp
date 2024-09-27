#include "Particle.h"

Particle::Particle(Vector3D pos, Vector3D vel)
{
	pose = physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	this->vel = vel;

	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1));
	renderItem = new RenderItem(sphere, &pose, physx::PxVec4(0, 0, 0, 1));
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void Particle::integrate(double t)
{
	pose.p = pose.p + physx::PxVec3(0, 0, t);
}
