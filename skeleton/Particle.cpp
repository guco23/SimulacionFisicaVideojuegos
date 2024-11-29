#include "Particle.h"
#include "const.h"

Particle::Particle(Vector3D pos, Vector3D vel, float masa, float damping, float factVel) : pos(pos), vel(vel), damp(damping), factVel(factVel)
{
	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1));
	renderItem = new RenderItem(sphere, &pose, physx::PxVec4(0, 0, 0, 1));
	pose = physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));

	accel = Vector3D(0, 0, 0);
	this->vel = vel * factVel;
	this->masa = masa / (factVel * factVel);
	 
	tFact = (this->vel.DotProduct(this->vel) / vel.DotProduct(vel));

	lifetime = 0;
}

Particle::Particle(const Particle& part) : vel(part.vel), pos(part.pos), damp(part.damp)
{
	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1));

	renderItem = new RenderItem(sphere, &pose, physx::PxVec4(0, 0, 0, 1));
	pose = physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));

	accel = part.accel;
	vel = part.vel;
	masa = part.masa;
	factVel = part.factVel;
	tFact = part.tFact;

	lifetime = 0;
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

Particle* Particle::clone() const
{
	return new Particle(*this);
}

void Particle::integrate(double t)
{
	vel = vel + accel * t;
	vel = vel * pow(damp, t);
	pos = pos + Vector3D( t * vel.getX(), t * vel.getY(), t * vel.getZ());
	pose.p = physx::PxVec3(pos.getX(), pos.getY(), pos.getZ());

	accel = Vector3D(0,0,0);
	lifetime += t;
}

void Particle::DeregisterRender()
{
	DeregisterRenderItem(renderItem);
}