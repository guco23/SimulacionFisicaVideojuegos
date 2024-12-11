#pragma once
#include <PxPhysics.h>
#include "RenderUtils.hpp"
#include "Vector3D.h"

using namespace physx;

class RigidBody
{
public:
	RigidBody(Vector3D transform, PxShape* shape, PxScene* scene, PxPhysics* phys, Vector4 color); //El resto de cosas que me dan ahora perezota
	~RigidBody();
private:
	RenderItem* render;
	PxRigidDynamic* solid;
	PxShape* shape;
	PxScene* scene;
	PxPhysics* phys;
};

