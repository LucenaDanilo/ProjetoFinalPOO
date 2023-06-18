#include "Helicoptero.hpp"
#include "ObjetoDeJogo.hpp"
#include "Game.hpp"

using std::string;

Helicoptero::Helicoptero() : path("./Sprites/helicoptero"), ObjetoDeJogo("./Sprites/helicoptero") , carga(10), tanque(130), pessoas(0), gas(nullptr), loud(nullptr) {
    setPosX(6);
    setPosY(28);
    ativa();
}

void Helicoptero::init() {
    Sprite* gas = new Sprite;
    Sprite* loud = new Sprite;
    gas->setPath("./Sprites/tanque");
    loud->setPath("./Sprites/carga");
    this->setSpriteGas(gas);
    this->setSpriteLoud(loud);
}

void Helicoptero::draw() {
    int x = getPosX();
    int y = getPosY();

    objSprite->draw(Game::screen, x, y);

    drawGas();
    drawLoud();
}

void Helicoptero::drawGas() const {
    this->gas->draw(Game::screen, 1, 20);
}

void Helicoptero::drawLoud() const {
    this->loud->draw(Game::screen, 1, 76);
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

    this->tanque -= 1;
    updateGas();
    updateLoud();
}

void Helicoptero::setSpriteGas(Sprite *g) {
    this->gas = g;
}

void Helicoptero::setSpriteLoud(Sprite *l) {
    this->loud = l;
}

void Helicoptero::updateGas() {
    string s = "             ";
    int valor = this->tanque/10;
    for (int i = 0; i < valor ; i++) {
        s[i] = '#';
    }

    gas->copiaString(s);
}

void Helicoptero::updateLoud() {
    string s = "             ";
    int valor = this->carga/10;
    for (int i = 0; i < valor ; i++) {
        s[i] = '#';
    }

    loud->copiaString(s);
}