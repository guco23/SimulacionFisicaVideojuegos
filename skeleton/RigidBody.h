#pragma once
#include <PxPhysics.h>
#include "RenderUtils.hpp"
#include "Vector3D.h"

using namespace physx;

class RigidBody
{
public:
	RigidBody(Vector3D transform, Vector3D vel, PxShape* shape);
private:
	PxRigidDynamic* solid;
};

