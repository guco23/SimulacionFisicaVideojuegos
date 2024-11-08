#include "Particle.h"
#include "iostream"

Particle::Particle(Vector3D pos, Vector3D vel, float damping) :  vel(vel), damp(damping)
{
	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1));
	renderItem = new RenderItem(sphere, &pose, physx::PxVec4(0, 0, 0, 1));
	setPos(pos);

}

Particle::Particle(const Particle& part) : vel(part.vel), pose(part.pose), damp(part.damp)
{
	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1));
	renderItem = new RenderItem(sphere, &pose, physx::PxVec4(0, 0, 0, 1));
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

Particle* Particle::clone() const
{
	return new Particle(*this);
}

void Particle::integrate(double t)
{
	vel = vel * pow(damp, t);
	pose.p = pose.p + physx::PxVec3(t * vel.getX(), t * vel.getY(), t * vel.getZ());
}

void Particle::DeregisterRender()
{
	DeregisterRenderItem(renderItem);
}

void Particle::setPos(Vector3D pos)
{
	pose = physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	
}

void Particle::setVel(Vector3D vel) {
	this->vel = vel;
}