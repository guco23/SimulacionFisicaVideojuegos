#pragma once
#include <PxPhysics.h>
#include "RenderUtils.hpp"
#include "Vector3D.h"

using namespace physx;

class RigidBody
{
public:
	RigidBody(Vector3D transform, PxShape* shape, PxScene* scene, PxPhysics* phys, Vector4 color, bool dynamic); //El resto de cosas que me dan ahora perezota
	~RigidBody();
	bool CheckActor(PxActor* actor);
	void AddForce(Vector3D);
	void SetMass(float);
	Vector3D GetPosition();
private:
	RenderItem* render;
	PxActor* solid;
	PxShape* shape;
	PxScene* scene;
	PxPhysics* phys;
	bool dynamic;
};

