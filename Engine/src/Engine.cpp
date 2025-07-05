#include "Engine/Engine.h"
#include "Engine/SDLWindow.h"
#include "Engine/Physics.h"

#include <memory>
#include <iostream>
#include <btBulletDynamicsCommon.h>

namespace Engine {

    std::unique_ptr<Engine::SDLWindow> window;

    // Physics globals
    btDiscreteDynamicsWorld* world = nullptr;
    btBroadphaseInterface* broadphase = nullptr;
    btDefaultCollisionConfiguration* collisionConfig = nullptr;
    btCollisionDispatcher* dispatcher = nullptr;
    btSequentialImpulseConstraintSolver* solver = nullptr;

    static btCollisionShape* groundShape = nullptr;
    static btCollisionShape* boxShape = nullptr;
    static btRigidBody* fallingBox = nullptr;

    void Init() {
        std::cout << "[Engine] Initialization..." << std::endl;
        window = std::make_unique<SDLWindow>();
        if (!window->Init("Genesis Engine", 800, 600)) {
            std::cerr << "[Engine] Window failed to initialize!" << std::endl;
            exit(1);
        }

        InitPhysics();
    }

    void InitPhysics() {
        collisionConfig = new btDefaultCollisionConfiguration();
        dispatcher = new btCollisionDispatcher(collisionConfig);
        broadphase = new btDbvtBroadphase();
        solver = new btSequentialImpulseConstraintSolver();
        world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);
        world->setGravity(btVector3(0, -9.81f, 0));

        std::cout << "[Engine] Physics initialized." << std::endl;
    }

    void UpdatePhysics(float deltaTime) {
        if (world) {
            world->stepSimulation(deltaTime);

            btTransform trans;
            fallingBox->getMotionState()->getWorldTransform(trans);
            std::cout << "[Physics] Box Y: " << trans.getOrigin().getY() << std::endl;
        }
    }

    void Run() {
        std::cout << "[Engine] Running..." << std::endl;

        while (window->IsRunning()) {
            window->PollEvents();

            UpdatePhysics(1.0f / 60.0f);
        }
    }

    void ShutdownPhysics() {
        world->removeRigidBody(fallingBox);
        delete fallingBox->getMotionState();
        delete fallingBox;
        delete boxShape;
        delete groundShape;

        delete world;
        delete solver;
        delete broadphase;
        delete dispatcher;
        delete collisionConfig;
    }

    void Shutdown() {
        ShutdownPhysics();
        window->Shutdown();
        std::cout << "[Engine] Shutdown complete." << std::endl;
    }

}
