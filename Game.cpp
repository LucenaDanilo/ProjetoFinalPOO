#include "Game.hpp"
#include "SpriteBase.hpp"
#include "Fase.hpp"
#include "ObjetoDeJogo.hpp"
#include "Menu.hpp"

Sprite Game::screen("./Sprites/screen");
Sprite Game::screenLimpa("./Sprites/screen");

void Game::run() {
    Menu menu;
    menu.init();
    menu.draw();
    while (true) {
        std::cout << menu;
        menu.update();
        menu.draw();

        if (menu.getStartGame()) {
            break;
        }
    }


    Fase fase1;
    fase1.init();
    fase1.draw();
    std::cout << fase1;

    while (true) {
        fase1.update();
        fase1.draw();
        std::cout << fase1;

        if (fase1.verificaFim()) {
            break;
        }
    }
    
}
