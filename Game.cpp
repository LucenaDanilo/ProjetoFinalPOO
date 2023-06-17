#include "Game.hpp"
#include "SpriteBase.hpp"
#include "Fase.hpp"
#include "ObjetoDeJogo.hpp"

Sprite Game::screen("./Sprites/screen");
Sprite Game::screenLimpa("./Sprites/screen");

void Game::run() {

    Fase fase1;
    fase1.init();
    fase1.draw();
    
    // std::string s;
    // getline(std::cin, s);
    // system("clear");
}
