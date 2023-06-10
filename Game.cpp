#include "Game.hpp"
#include "SpriteBase.hpp"
#include "Fase.hpp"

Sprite Game::screen("./Sprites/screen");
Sprite Game::screenLimpa("./Sprites/screen");

void Game::run() {

    Fase fase1;
    fase1.init();
    
    // std::string s;
    // getline(std::cin, s);
    // system("clear");
}

// void Game::reapontar() {
//     delete Game::pScreen;
//     Game::pScreen = new Sprite("./Sprites/screen");
// }