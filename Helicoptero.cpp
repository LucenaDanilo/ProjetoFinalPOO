#include "Helicoptero.hpp"
#include "ObjetoDeJogo.hpp"
#include "Game.hpp"

using std::string;

Helicoptero::Helicoptero() : path("./Sprites/SpritesHeli/helicoptero1"), ObjetoDeJogo("./Sprites/SpritesHeli/helicoptero1") , 
    carga(10), tanque(130), pessoas(0), gas(nullptr), loud(nullptr), contSprite(0) {
    setPosX(6);
    setPosY(28);
    ativa();
}

void Helicoptero::init() {
    // Init no array de sprites
    string paths[] = {"./Sprites/SpritesHeli/helicoptero1", "./Sprites/SpritesHeli/helicoptero2" ,
    "./Sprites/SpritesHeli/helicoptero3", "./Sprites/SpritesHeli/helicoptero4", "./Sprites/SpritesHeli/helicoptero5" ,
    "./Sprites/SpritesHeli/helicoptero6", "./Sprites/SpritesHeli/helicoptero7", "./Sprites/SpritesHeli/helicoptero8"};

    for (const auto&path: paths) {
        Sprite *s = new Sprite(path);
        spriteHelis.push_back(s);
    }

    // Init no display do Gas e loud
    Sprite* gas = new Sprite;
    Sprite* loud = new Sprite;
    gas->setPath("./Sprites/tanque");
    loud->setPath("./Sprites/carga");
    this->setSpriteGas(gas);
    this->setSpriteLoud(loud);
}

void Helicoptero::draw() const {
    int x = getPosX();
    int y = getPosY();

    spriteHelis[contSprite]->draw(Game::screen, x, y);

    drawGas();
    drawLoud();
}

void Helicoptero::drawGas() const {
    this->gas->draw(Game::screen, 1, 20);
}

void Helicoptero::drawLoud() const {
    this->loud->draw(Game::screen, 1, 76);
}

void Helicoptero::update(string entrada) {
    updatePos(entrada);
    updateSprite();
    updateGas();
    updateLoud();

    contSprite++;
    if (contSprite > 7) {
        contSprite = 0;
    }
}

void Helicoptero::updateSprite() {
    // JAJA EU VOLTO
    string path = "./Sprites/SpritesHeli/helicoptero3";

    char caractere = static_cast<char>(contSprite);
    path[35] = 2;

    this->setSprite(path);
}

void Helicoptero::updatePos(string c) {
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

void Helicoptero::updateGas() {
    this->tanque -= 1;
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

void Helicoptero::setSpriteGas(Sprite *g) {
    this->gas = g;
}

void Helicoptero::setSpriteLoud(Sprite *l) {
    this->loud = l;
}

