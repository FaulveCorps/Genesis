#include "Game/Game.h"
#include "Genesis/Debug/Log.h"

void Game::Init() {
    LOG_INFO("[Game] Init");
}

void Game::Update(float dt) {
    // game logic here
}

void Game::Render() {
    // rendering calls
}

void Game::Shutdown() {
    LOG_INFO("[Game] Shutdown");
}
