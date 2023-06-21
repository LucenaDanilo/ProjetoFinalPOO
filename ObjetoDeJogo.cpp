#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"

ObjetoDeJogo::ObjetoDeJogo(const string& s) : GameBase(), objSprite(nullptr)
    , x(0), y(0), ativo(false), indSprite(0), direita(true) {
    setSprite(s);
}

ObjetoDeJogo::~ObjetoDeJogo() {
    delete objSprite;
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
    setIndSprites(getIndSprite() + 1);
    if (getIndSprite() > getNSprites() - 1) {
        setIndSprites(0);
    }
}

void ObjetoDeJogo::setSprite(const string& s) {
    Sprite* h = new Sprite;
    h->readPath(s);
    objSprite = h;
}

void ObjetoDeJogo::moveTo(int x, int y) {
    setPosX(x);
    setPosY(y);
}

void ObjetoDeJogo::insereSprite(std::string path) {
    Sprite *s = new Sprite(path);
    this->spritesObj.push_back(s);
}
