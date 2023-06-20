#include "Fase.hpp"
#include "Game.hpp"
#include "ObjetoDeJogo.hpp"
#include "Helicoptero.hpp"
#include "Pessoa.hpp"
#include "GalaoGasolina.hpp"
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

    ObjetoDeJogo *objs[] = {heroi, new Pessoa(32, 60), new Pessoa(32, 110), 
    new Pessoa(32, 54), new Pessoa(32, 63), new Pessoa(32, 116), new GalaoGasolina};

    for (const auto& obj : objs) {
        listObjJogo.push_back(obj);
        obj->init();
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
    
    updateColisao(entrada);
    updateObjetosJogo(entrada);
    incrementaResgatados(entrada);
}

void Fase::updateColisao(std::string entrada) const {
    auto heroi = listObjJogo.front();

    for (const auto&obj : listObjJogo) {
        if (obj != heroi) {
            if (verificaColisaoObjJogo(*heroi, *obj) && entrada[0] == 'x') {
                if (obj->getId() == "Pessoa") {
                    if (heroi->getPessoas() < 4) {
                        if (heroi->colideCom(*obj) && obj->getAtivo()) {
                            capturaPessoa(heroi, obj);
                        }        
                    } 
                } else if (obj->getId() == "GalaoGasolina") {
                    capturaGalao(heroi, obj);
                }
            }
        }
    }
}

void Fase::capturaPessoa(ObjetoDeJogo *heroi, ObjetoDeJogo *obj) const {
    heroi->setPeso(heroi->getPeso() + obj->getPeso());
    heroi->incrementaPessoas(1);
    obj->desativa();
}

void Fase::capturaGalao(ObjetoDeJogo *heroi, ObjetoDeJogo *obj) const {
    int gas = heroi->getTanque() + obj->getTanque();
    heroi->setTanque(gas);
    obj->desativa();  
}

bool Fase::verificaColisaoObjJogo(ObjetoDeJogo &heroi, ObjetoDeJogo& obj) const {
    if (heroi.colideCom(obj) && obj.getAtivo()) {
        return true;
    }
    return false;
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

void Fase::incrementaResgatados(std::string entrada) {
    auto heroi = this->listObjJogo.front();
    int pessoas = heroi->getPessoas();

    if (verificaResgate() && entrada[0] == 'x') {
        // adiciona a pessoa em resgatados e tira do helicoptero
        resgatados += pessoas;
        std::string stringResgatados = std::to_string(resgatados);
        heroi->incrementaPessoas(-pessoas);
        heroi->setPeso(heroi->getPeso() - 68 * pessoas);

        //transforma o display no número de pessoas resgatadas
        sprResgatados.copiaString(stringResgatados);
    }
}

bool Fase::verificaFim() {

    if (verificaVitoria()) {
        telaVitoria();
        return true;
    }

    if (verificaDerrota()) {
        telaDerrota();
        return true;
    }
    return false;
}

bool Fase::verificaVitoria() const {
    auto heroi = this->listObjJogo.front();

    if(verificaColisaoRescueBase()) {
        if (getResgatados() == 5) {
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

void Fase::telaVitoria() {
    auto heroi = this->listObjJogo.front();
    
    heroi->updateVitoria();
    heroi->draw();
    vitoria.draw(Game::screen, 18, 50);
    system("clear");
    Game::screen.show();
}

void Fase::telaDerrota() {
    derrota.draw(Game::screen, 18, 45);
    system("clear");
    Game::screen.show();
}

void Fase::setObjetoJogo(ObjetoDeJogo* obj) {
    listObjJogo.push_front(obj);
}

