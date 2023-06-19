#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"

ObjetoDeJogo::ObjetoDeJogo(const string& s) : GameBase(), objSprite(nullptr)
    , x(0), y(0), ativo(false), indSprite(0) {
    setSprite(s);
}

bool ObjetoDeJogo::colideCom(const ObjetoDeJogo &obj) const {
    int x1, y1, h1, w1;
    int x2, y2, h2, w2;

    x1 = this->getPosX();
    y1 = this->getPosY();
    h1 = this->objSprite->getH();
    w1 = this->objSprite->getW();

    x2 = obj.getPosX();
    y2 = obj.getPosY();
    h2 = obj.objSprite->getH();
    w2 = obj.objSprite->getW();

    //std::cout << "x1: " << x1 << " | h1: " << h1 << " | x2: " << x2;
    if ((x1 + h1 >= x2) && (x1 <= x2)) {
        //std::cout << "primeiro!";
        if ((y1 + w1 > y2) && (y1 < y2)) {
            return true;
        }
    }

    return false;
}

void ObjetoDeJogo::updateSprite() {
    indSprite++;
    if (indSprite > nSprites - 1) {
        indSprite = 0;
    }
}

void ObjetoDeJogo::ativa() { 
    ativo = true;
}

void ObjetoDeJogo::desativa() {
    ativo = false;
}

void ObjetoDeJogo::setPosX(int x) {
    this->x = x;
}

void ObjetoDeJogo::setPosY(int y) {
    this->y = y;
}

void ObjetoDeJogo::setSprite(const string& s) {
    Sprite* h = new Sprite;
    h->setPath(s);
    objSprite = h;
}

int ObjetoDeJogo::getPosX() const { 
    return x;
}

int ObjetoDeJogo::getPosY() const { 
    return y;
}

bool ObjetoDeJogo::getAtivo() const { 
    return ativo;
}

int ObjetoDeJogo::getIndSprite() const {
    return indSprite;
}

int ObjetoDeJogo::getNSprites() const {
    return nSprites;    
}

void ObjetoDeJogo::moveTo(int x, int y) {
    setPosX(x);
    setPosY(y);
}

void ObjetoDeJogo::insereSprite(std::string path) {
    Sprite *s = new Sprite(path);
    this->spritesObj.push_back(s);
}
