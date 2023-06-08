#include "Fase.hpp"
#include "Game.hpp"

Fase::Fase( const string &backPath ) : GameBase(), background(backPath) {
    //
}

void Fase::init() {}
void Fase::update() {}
void Fase::draw() {}

void Fase::show() {
    background.draw( Game::pScreen , 0, 0);
}