#include "Game/Game.h"
#include "Genesis/Debug/Log.h"
#include "Genesis/Renderer/BasicRenderer.h"

namespace Game {

    void Init() {
        LOG_INFO("[Game] Init");
        // Future: Load levels, setup game state
    }

    void Update(float deltaTime) {
        // Future: Handle input, update ECS
    }

    void Game::Render() {
        Genesis::BasicRenderer::Render();
    }

    void Shutdown() {
        LOG_INFO("[Game] Shutdown");
        // Future: Cleanup
    }

}
