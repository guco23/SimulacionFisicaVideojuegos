#include "Particle.h"

Particle::Particle(Vector3D pos, Vector3D vel, float damping) :  vel(vel), pose(physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()))), damp(damping)
{
	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1));
	renderItem = new RenderItem(sphere, &pose, physx::PxVec4(0, 0, 0, 1));
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t, Vector3D accel)
{
	vel = vel * pow(damp, t);
	pose.p = pose.p + physx::PxVec3(t * vel.getX(), t * vel.getY(), t * vel.getZ());
}