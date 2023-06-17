#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"

ObjetoDeJogo::ObjetoDeJogo(const string& s) : GameBase(), objSprite(nullptr), x(0), y(0), ativo(false) {
    setSprite(s);
}

bool ObjetoDeJogo::colideCom(const ObjetoDeJogo&) const {
    //
    return true;
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

void ObjetoDeJogo::moveTo(int x, int y) {
    setPosX(x);
    setPosY(y);
}