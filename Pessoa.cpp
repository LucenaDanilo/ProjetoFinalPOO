#include "Pessoa.hpp"
#include "ObjetoDeJogo.hpp"
#include "Game.hpp"

Pessoa::Pessoa(int x, int y) : ObjetoDeJogo("./Sprites/pessoa") , peso(0) {
    setPosX(x);
    setPosY(y);
    ativa();
}

void Pessoa::draw() {
    int x = getPosX();
    int y = getPosY();
    objSprite->draw(Game::screen, x, y);
}   
