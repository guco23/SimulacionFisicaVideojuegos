#include "Particle.h"

Particle::Particle(Vector3D pos, Vector3D vel) :  vel(vel), pose(physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ())))
{
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
	pose.p = pose.p + physx::PxVec3(t * vel.getX(), t * vel.getY(), t * vel.getZ());
}