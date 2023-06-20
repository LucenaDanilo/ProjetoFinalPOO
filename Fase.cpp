#include "Fase.hpp"
#include "Game.hpp"
#include "ObjetoDeJogo.hpp"
#include "Helicoptero.hpp"
#include "Pessoa.hpp"
#include <iostream>
#include <list>

Fase::Fase() : GameBase(), resgatados(0), sprResgatados("./Sprites/resgatados") ,
    vitoria("./Sprites/Msgs/vitoria.txt"), derrota("./Sprites/Msgs/derrota.txt") {
    //
}

Fase::~Fase() {
    for (const auto&obj : listObjJogo) {
        delete obj;
    }
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

    ObjetoDeJogo *objs[] = {heroi, new Pessoa(32, 60), 
        new Pessoa(32, 110)};

    for (int i = 0; i < 3; i++) {
        listObjJogo.push_back(objs[i]);
        objs[i]->init();
    }   
}

void Fase::draw() const {
    drawBackground();
    drawObjetosJogo();
}

void Fase::drawBackground() const {
    Game::screen.limpaScreen(Game::screenLimpa);

    // desenhando o background...
    background.draw(Game::screen, 7, 8);
    ilha1.draw(Game::screen, 24, 35);
    ilha2.draw(Game::screen, 24, 85);
    sprResgatados.draw(Game::screen, 1, 147);
}

void Fase::drawObjetosJogo() const {
    // desenhar todos os objetos de jogo
    for (const auto&obj : listObjJogo) {
        if (obj->getAtivo())
            obj->draw();
    }  
}

void Fase::update() {
    // dar update no array de objetos de jogo
    
    std::string entrada;
    getline(std::cin, entrada);
    system("clear");
    
    updateColisao();
    updateObjetosJogo(entrada);
    incrementaResgatados();
}

void Fase::updateColisao() const {
    auto heroi = listObjJogo.front();

    for (const auto&obj : listObjJogo) {
        if (obj != heroi)
            if (heroi->colideCom(*obj) && obj->getAtivo()) {
                heroi->setPeso(heroi->getPeso() + obj->getPeso());
                heroi->incrementaPessoas(1);
                std::cout << "nPessoas: " << heroi->getPessoas();
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

void Fase::show() {
   Game::screen.show();
}

bool Fase::verificaColisaoRescueBase() const {
    auto heroi = this->listObjJogo.front();

    if (heroi->getPosX() >= 26 && heroi->getPosX() <= 33) {
        if (heroi->getPosY() <= 10 && heroi->getPosY() >= 4) {
            return true;
        }
    }
    return false;
}

bool Fase::verificaResgate() const {
    auto heroi = this->listObjJogo.front();

    if (verificaColisaoRescueBase() and heroi->getPessoas() != 0) {
        return true;
    }
    return false;
}

void Fase::incrementaResgatados() {
    auto heroi = this->listObjJogo.front();
    int pessoas = heroi->getPessoas();
    std::string stringPessoas = std::to_string(pessoas);


    if (verificaResgate()) {
        // adiciona a pessoa em resgatados e tira do helicoptero
        resgatados += pessoas;
        heroi->incrementaPessoas(-pessoas);
        heroi->setPeso(heroi->getPeso() - 55 * pessoas);

        //transforma o display no número de pessoas resgatadas
        sprResgatados.copiaString(stringPessoas);
        //sprResgatados.draw(Game::screen, )
    }
}

bool Fase::verificaFim() {
    if (verificaVitoria()) {
        vitoria.draw(Game::screen, 18, 50);
        system("clear");
        Game::screen.show();
        return true;
    }

    if (verificaDerrota()) {
        derrota.draw(Game::screen, 18, 45);
        system("clear");
        Game::screen.show();
        return true;
    }
    return false;
}

bool Fase::verificaVitoria() const {
    auto heroi = this->listObjJogo.front();

    if(verificaColisaoRescueBase()) {
        if (getResgatados() == 2) {
            return true;
        }
    }
    return false;
}

bool Fase::verificaDerrota() const {
    auto heroi = this->listObjJogo.front();

    if (heroi->getTanque() < 1) {
        return true;
    }

    return false;
}

void Fase::setObjetoJogo(ObjetoDeJogo* obj) {
    listObjJogo.push_front(obj);
}

