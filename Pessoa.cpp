#include "Pessoa.hpp"
#include "ObjetoDeJogo.hpp"
#include "Game.hpp"

Pessoa::Pessoa(int x, int y) : ObjetoDeJogo("./Sprites/SpritesPessoa/pessoa") , peso(55) {
    setPosX(x);
    setPosY(y);
    ativa();
}

void Pessoa::init() {
    string paths[] = {"./Sprites/SpritesPessoa/pessoa", "./Sprites/SpritesPessoa/pessoa2" ,
    "./Sprites/SpritesPessoa/pessoa3", "./Sprites/SpritesPessoa/pessoa4", "./Sprites/SpritesPessoa/pessoa5" ,
    "./Sprites/SpritesPessoa/pessoa6", "./Sprites/SpritesPessoa/pessoa7"};

    int cont = 0;
    for (const auto&path: paths) {
        insereSprite(path);
        cont++;
    }

    setNSprites(cont);
}

void Pessoa::update(string s) {
    updateSprite();
}

void Pessoa::draw() const {
    int x = getPosX();
    int y = getPosY();
    getSprite()->draw(Game::screen, x, y);
}   