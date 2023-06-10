#include "Fase.hpp"
#include "Game.hpp"

Fase::Fase( const string &backPath ) : GameBase(), background(backPath) {
    //
}

void Fase::init() {
    // iniciar o array de objetos de jogo e background
    background.draw(Game::screen, 7, 8);
    Game::screen.show();
}

void Fase::update() {
    // dar update no array de objetos de jogo
}

void Fase::draw() {
    // desenhar o background
    // desenhar todos os objetos de jogo 
}

void Fase::show() {
   // nao sei ainda
}