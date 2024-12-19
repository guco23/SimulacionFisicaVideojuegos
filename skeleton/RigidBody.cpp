#include "RigidBody.h"

RigidBody::RigidBody(Vector3D transform, PxShape* shape, PxScene* scene, PxPhysics* phys, Vector4 color, bool dynamic) : shape(shape), scene(scene), phys(phys), dynamic(dynamic)
{
	if (dynamic) {
		PxRigidDynamic* dyn = phys->createRigidDynamic(PxTransform(transform.getX(), transform.getY(), transform.getZ()));
		
		dyn->attachShape(*shape);
		scene->addActor(*dyn);
		render = new RenderItem(shape, dyn, color);
		solid = dyn;
	}
	else {
		PxRigidStatic* st = phys->createRigidStatic(PxTransform(transform.getX(), transform.getY(), transform.getZ()));

		st->attachShape(*shape);
		scene->addActor(*st);
		render = new RenderItem(shape, st, color);
		solid = st;
	}
}

RigidBody::~RigidBody()
{
	DeregisterRenderItem(render);
}

bool RigidBody::CheckActor(PxActor* actor)
{
	return actor == solid;
}

void RigidBody::AddForce(Vector3D force) {
	if (dynamic) {
		PxRigidDynamic* dyn = static_cast<PxRigidDynamic*>(solid);
		dyn->addForce(PxVec3(force.getX(), force.getY(), force.getZ()));
	}
}

void RigidBody::SetMass(float mass)
{
	if (dynamic) {
		PxRigidDynamic* dyn = static_cast<PxRigidDynamic*>(solid);
		dyn->setMass(mass);
	}
}

Vector3D RigidBody::GetPosition()
{
	PxRigidActor* act = static_cast<PxRigidActor*>(solid);
	PxTransform t = act->getGlobalPose();
	return Vector3D(t.p.x, t.p.y, t.p.z);
}
