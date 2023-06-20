#include "GalaoGasolina.hpp"
#include "ObjetoDeJogo.hpp"
#include "Game.hpp"

GalaoGasolina::GalaoGasolina() : ObjetoDeJogo("./Sprites/SpritesGalao/galao1"), 
        tanque(100), peso(0) {
    setId("GalaoGasolina");
    setPosX(28);
    setPosY(144);
    ativa();
}

void GalaoGasolina::init() {
    string paths[] = {"./Sprites/SpritesGalao/galao1", "./Sprites/SpritesGalao/galao2" ,
    "./Sprites/SpritesGalao/galao3", "./Sprites/SpritesGalao/galao4"};

    int cont = 0;
    for (const auto&path: paths) {
        insereSprite(path);
        cont++;
    }

    setNSprites(cont);
}

void GalaoGasolina::update(string s) {
    updateSprite();
}

void GalaoGasolina::draw() const {
    int x = getPosX();
    int y = getPosY();
    getSprite()->draw(Game::screen, x, y);
}   