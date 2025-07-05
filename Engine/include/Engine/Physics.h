#pragma once
#include <btBulletDynamicsCommon.h>

btRigidBody* CreateRigidBody(btDiscreteDynamicsWorld* world, float mass, btCollisionShape* shape, const btVector3& position);

namespace Engine {
    void InitPhysics();
    void UpdatePhysics(float deltaTime);
    void ShutdownPhysics();

    btDiscreteDynamicsWorld* GetPhysicsWorld();
    btRigidBody* CreateRigidBody(btDiscreteDynamicsWorld* world, float mass, btCollisionShape* shape, const btVector3& pos);
}