#include "Particle.h"
#include "const.h"

Particle::Particle(Vector3D pos, Vector3D vel, float masa, float damping, float factVel) :  vel(vel), damp(damping), factVel(factVel)
{
	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1));
	renderItem = new RenderItem(sphere, &pose, physx::PxVec4(0, 0, 0, 1));
	setPos(pos);

	accel = Vector3D(0, 0, 0);
	this->vel = vel * factVel;
	this->masa = masa / (factVel * factVel);
	 
	tFact = (this->vel.DotProduct(this->vel) / vel.DotProduct(vel));

	lifetime = 0;
}

Particle::Particle(const Particle& part) : vel(part.vel), pose(part.pose), damp(part.damp)
{
	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1));
	renderItem = new RenderItem(sphere, &pose, physx::PxVec4(0, 0, 0, 1));

	accel = part.accel;
	vel = part.vel;
	masa = part.masa;
	grav = part.grav;
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
	pose.p = pose.p + physx::PxVec3(t * vel.getX(), t * vel.getY(), t * vel.getZ());

	lifetime += t;
}

void Particle::setPos(Vector3D pos)
{
	pose = physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	
}

void Particle::setVel(Vector3D vel) {
	this->vel = vel;
}

Vector3D Particle::getPos() const
{
	return Vector3D(pose.p.x, pose.p.y, pose.p.z);
}

Vector3D Particle::getVel() const
{
	return vel;
}

double Particle::getLifetime() const
{
	return lifetime;
}

void Particle::DeregisterRender()
{
	DeregisterRenderItem(renderItem);
}