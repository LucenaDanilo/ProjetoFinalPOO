#include "Helicoptero.hpp"
#include "ObjetoDeJogo.hpp"
#include "Game.hpp"

Helicoptero::Helicoptero() : path("./Sprites/helicoptero"), ObjetoDeJogo("./Sprites/helicoptero") , carga(0), tanque(100), pessoas(0) {
    setPosX(10);
    setPosY(10);
    ativa();
}

void Helicoptero::draw() {
    objSprite->draw(Game::screen, 6, 28);
}
