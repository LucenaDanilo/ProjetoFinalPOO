#include "Fase.hpp"
#include "Game.hpp"
#include "ObjetoDeJogo.hpp"
#include "Helicoptero.hpp"
#include "Pessoa.hpp"

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
    Sprite* gas = new Sprite;
    Sprite* loud = new Sprite;
    gas->setPath("./Sprites/tanque");
    loud->setPath("./Sprites/carga");
    heroi->setSpriteGas(gas);
    heroi->setSpriteLoud(loud);
    

    Pessoa* p1 = new Pessoa(32, 60);
    Pessoa* p2 = new Pessoa(32, 110);
    listObjJogo.push_back(heroi);
    listObjJogo.push_back(p1);
    listObjJogo.push_back(p2);
}

void Fase::draw() {
    Game::screen.limpaScreen(Game::screenLimpa);

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

void Fase::update() {
    // dar update no array de objetos de jogo
    std::string s;
    getline(std::cin, s);
    system("clear");

    for (const auto&obj : listObjJogo) {
        if (obj->getAtivo())
            obj->update(s);
    }
}

void Fase::show() {
   // nao sei ainda
}

void Fase::setObjetoJogo(ObjetoDeJogo* obj) {
    listObjJogo.push_front(obj);
}