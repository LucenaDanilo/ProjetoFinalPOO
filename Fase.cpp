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
    //Helicoptero heroi; // ERRO AQUI NA CRIAÇÃO DO HELICOPTERO

    // listObjJogo.push_front();
}

void Fase::update() {
    // dar update no array de objetos de jogo
}

void Fase::draw() {
    // desenhar o background
    // desenhar todos os objetos de jogo
    background.draw(Game::screen, 7, 8);
    ilha1.draw(Game::screen, 24, 35);
    ilha2.draw(Game::screen, 24, 85);
    Game::screen.show();
}

void Fase::show() {
   // nao sei ainda
}

void Fase::setObjetoJogo(ObjetoDeJogo* obj) {
    listObjJogo.push_front(obj);
}