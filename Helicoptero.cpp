#include "Helicoptero.hpp"
#include "ObjetoDeJogo.hpp"
#include "Game.hpp"

using std::string;

Helicoptero::Helicoptero() : path("./Sprites/helicoptero"), ObjetoDeJogo("./Sprites/helicoptero") , carga(0), tanque(100), pessoas(0), gas(nullptr), loud(nullptr) {
    setPosX(6);
    setPosY(28);
    ativa();
}

void Helicoptero::draw() {
    int x = getPosX();
    int y = getPosY();

    objSprite->draw(Game::screen, x, y);

    drawGas();
    drawLoad();
}

void Helicoptero::drawGas() const {
    string gasString = "";
    int nGas = tanque/10;

    for (int i = 0; i < nGas; i++) {
        gasString[i] = '#';
    }

    //this->gas.copiaString(gasString);
}

void Helicoptero::drawLoad() const {

}


void Helicoptero::update(string c) {
    int x = getPosX();
    int y = getPosY();

    if (c[0] == 'w' | c[0] == 'W') {
        moveTo(x-1, y);
    } else if (c[0] == 's' || c[0] == 'S') {
        moveTo(x+1, y);
    } else if (c[0] == 'a' || c[0] == 'A') {
        moveTo(x, y-3);
    } else if (c[0] == 'd' || c[0] == 'D') {
        moveTo(x, y+3);
    }
}