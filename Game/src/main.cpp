#include "Engine/SDLWindow.h"
#include "Engine/Physics.h"
#include <btBulletDynamicsCommon.h>
#include <iostream>
#include "Engine/Physics.h"

int main() {
    Engine::InitPhysics();

    // Create a static ground plane (mass = 0)
    btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 0);
    Engine::CreateRigidBody(Engine::GetPhysicsWorld(), 0.0f, groundShape, btVector3(0, -1, 0));

    // Create a dynamic box (mass = 1)
    btCollisionShape* boxShape = new btBoxShape(btVector3(1, 1, 1));
    btRigidBody* boxBody = Engine::CreateRigidBody(Engine::GetPhysicsWorld(), 1.0f, boxShape, btVector3(0, 10, 0));

    for (int i = 0; i < 300; ++i) {
        Engine::UpdatePhysics(1.0f / 60.0f);
        btTransform trans;
        boxBody->getMotionState()->getWorldTransform(trans);
        btVector3 pos = trans.getOrigin();
        std::cout << "Box Y: " << pos.getY() << std::endl;
    }

    Engine::ShutdownPhysics();
    return 0;
}
