#include "RigidBody.h"

RigidBody::RigidBody(Vector3D transform, PxShape* shape, PxScene* scene, PxPhysics* phys, Vector4 color) : shape(shape), scene(scene), phys(phys)
{
	solid = phys->createRigidDynamic(PxTransform(transform.getX(), transform.getY(), transform.getZ()));
	solid->attachShape(*shape);
	scene->addActor(*solid);
	render = new RenderItem(shape,  solid, color);
}

RigidBody::~RigidBody()
{
}
