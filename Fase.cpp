#include "Fase.hpp"
#include "Game.hpp"
#include "ObjetoDeJogo.hpp"
#include "Helicoptero.hpp"

Fase::Fase() : GameBase() {
    //
}

void Fase::init() {
    // iniciando o background
    background.setPath("./Sprites/pontes");
    ilha1.setPath("./Sprites/ilha");
    ilha2.setPath("./Sprites/ilha");

    // iniciando os objetos de jogo
    Helicoptero* heroi = new Helicoptero;
    listObjJogo.push_back(heroi);
}

void Fase::update() {
    // dar update no array de objetos de jogo
}

void Fase::draw() {
    // desenhando o background...
    background.draw(Game::screen, 7, 8);
    ilha1.draw(Game::screen, 24, 35);
    ilha2.draw(Game::screen, 24, 85);

    // desenhar todos os objetos de jogo
    for (const auto&obj : listObjJogo) {
        if (obj->getAtivo())
            obj->draw();
    }

    Game::screen.show();
}

void Fase::show() {
   // nao sei ainda
}

void Fase::setObjetoJogo(ObjetoDeJogo* obj) {
    listObjJogo.push_front(obj);
}