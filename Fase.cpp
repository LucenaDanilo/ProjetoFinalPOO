#include "Fase.hpp"
#include "Game.hpp"
#include "ObjetoDeJogo.hpp"
#include "Helicoptero.hpp"
#include "Pessoa.hpp"
#include <iostream>
#include <list>
#include <iterator>

Fase::Fase() : GameBase(), resgatados(0) {
    //
}

void Fase::init() {
    system("clear");

    initBackgroud();
    initObjetosJogo();
    drawBackground();
}

void Fase::initBackgroud() {
    // iniciando o background
    background.setPath("./Sprites/pontes");
    ilha1.setPath("./Sprites/ilha");
    ilha2.setPath("./Sprites/ilha");
}

void Fase::initObjetosJogo() {
     // iniciando os objetos de jogo
    Helicoptero* heroi = new Helicoptero;
    heroi->init();
    
    Pessoa* p1 = new Pessoa(32, 60);
    Pessoa* p2 = new Pessoa(32, 110);

    ObjetoDeJogo *objs[] = {heroi, new Pessoa(32, 60), 
        new Pessoa(32, 110)};

    for (int i = 0; i < 3; i++) {
        listObjJogo.push_back(objs[i]);
    }   
}

void Fase::draw() {
    drawBackground();
    drawObjetosJogo();
}

void Fase::update() {
    // dar update no array de objetos de jogo
    
    std::string entrada;
    getline(std::cin, entrada);
    system("clear");
    
    updateObjetosJogo(entrada);
    updateColisao();
}

void Fase::show() {
   Game::screen.show();
}

void Fase::setObjetoJogo(ObjetoDeJogo* obj) {
    listObjJogo.push_front(obj);
}

void Fase::drawBackground() const {
    Game::screen.limpaScreen(Game::screenLimpa);

    // desenhando o background...
    background.draw(Game::screen, 7, 8);
    ilha1.draw(Game::screen, 24, 35);
    ilha2.draw(Game::screen, 24, 85);
}

void Fase::drawObjetosJogo() const {
    // desenhar todos os objetos de jogo
    for (const auto&obj : listObjJogo) {
        if (obj->getAtivo())
            obj->draw();
    }  
}

void Fase::updateColisao() const {
    auto heroi = listObjJogo.front();

    for (const auto&obj : listObjJogo) {
        if (obj != heroi)
            if (heroi->colideCom(*obj) && obj->getAtivo()) {
                heroi->setPeso(heroi->getPeso() + obj->getPeso());
                obj->desativa();
            }        
    }
}

void Fase::updateObjetosJogo(std::string entrada) const {
    for (const auto&obj : listObjJogo) {
        if (obj->getAtivo())
            obj->update(entrada);
    }
}