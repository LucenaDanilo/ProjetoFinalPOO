#include "Helicoptero.hpp"
#include "ObjetoDeJogo.hpp"
#include "Game.hpp"

using std::string;

Helicoptero::Helicoptero() : ObjetoDeJogo("./Sprites/SpritesHeli/helicoptero1") , 
    carga(22), tanque(300), pessoas(0), gas(nullptr), loud(nullptr) {
    setPosX(6);
    setPosY(28);
    ativa();
}

void Helicoptero::init() {
    // Init no array de sprites
    string paths[] = {"./Sprites/SpritesHeli/helicoptero1", "./Sprites/SpritesHeli/helicoptero2" ,
    "./Sprites/SpritesHeli/helicoptero3", "./Sprites/SpritesHeli/helicoptero4", "./Sprites/SpritesHeli/helicoptero5" ,
    "./Sprites/SpritesHeli/helicoptero6", "./Sprites/SpritesHeli/helicoptero7", "./Sprites/SpritesHeli/helicoptero8"};

    int cont = 0;
    for (const auto&path: paths) {
        insereSprite(path);
        cont++;
    }

    setNSprites(cont);

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

    getSprite()->draw(Game::screen, x, y);

    drawGas();
    drawLoud();
}

void Helicoptero::drawGas() const {
    this->gas->draw(Game::screen, 1, 20);
}

void Helicoptero::drawLoud() const {
    this->loud->draw(Game::screen, 1, 76);
}

void Helicoptero::updateVitoria() {
    updateSprite();
    updateGas();
    updateLoud();  
}

void Helicoptero::update(string entrada) {
    updatePos(entrada);
    updateSprite();
    updateGas();
    updateLoud();   
}

void Helicoptero::updatePos(string c) {
    int x = getPosX();
    int y = getPosY();
    int h = getSprite()->getH();
    int w = getSprite()->getW();

    if (c[0] == 'w' | c[0] == 'W') {
        if (x > 3) {
            moveTo(x-1, y);
        }
    } else if (c[0] == 's' || c[0] == 'S') {
        if (x + h < 39) {
            moveTo(x+1, y);
        }
    } else if (c[0] == 'a' || c[0] == 'A') {
        if (y > 2) {
            moveTo(x, y-3);
        }
        
    } else if (c[0] == 'd' || c[0] == 'D') {
        if (y + w < 157) {
            moveTo(x, y+3);
        }   
    }
}

void Helicoptero::updateGas() {
    this->tanque -= 1;
    string s = "             ";
    int valor = this->tanque/22;
    for (int i = 0; i < valor ; i++) {
        s[i] = '#';
    }

    gas->copiaString(s);
}

void Helicoptero::updateLoud() {
    string s = "             ";
    int valor = this->carga/22;
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

