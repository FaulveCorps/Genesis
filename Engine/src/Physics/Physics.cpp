#include "Engine/Physics.h"

static btDiscreteDynamicsWorld* world = nullptr;
static btCollisionDispatcher* dispatcher = nullptr;
static btBroadphaseInterface* broadphase = nullptr;
static btSequentialImpulseConstraintSolver* solver = nullptr;
static btDefaultCollisionConfiguration* config = nullptr;


void Engine::InitPhysics() {
    config = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(config);
    broadphase = new btDbvtBroadphase();
    solver = new btSequentialImpulseConstraintSolver();
    world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, config);
    world->setGravity(btVector3(0, -9.81f, 0));
}

void Engine::UpdatePhysics(float deltaTime) {
    if (world)
        world->stepSimulation(deltaTime);
}

void Engine::ShutdownPhysics() {
    if (world) {
        delete world;
        delete solver;
        delete broadphase;
        delete dispatcher;
        delete config;
        world = nullptr;
    }
}

btDiscreteDynamicsWorld* Engine::GetPhysicsWorld() {
    return world;
}

btRigidBody* Engine::CreateRigidBody(btDiscreteDynamicsWorld* world, float mass, btCollisionShape* shape, const btVector3& pos) {
    btVector3 inertia(0, 0, 0);
    if (mass != 0.0f)
        shape->calculateLocalInertia(mass, inertia);

    btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), pos));
    btRigidBody::btRigidBodyConstructionInfo info(mass, motionState, shape, inertia);
    btRigidBody* body = new btRigidBody(info);
    world->addRigidBody(body);
    return body;
}
