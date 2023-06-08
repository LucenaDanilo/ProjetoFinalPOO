#include "Game.hpp"
#include "SpriteBase.hpp"
#include "Fase.hpp"

SpriteBase *Game::pScreen = new Sprite("./Sprites/screenInitial");

void Game::run() {
    Fase fase1;
    fase1.show();
}