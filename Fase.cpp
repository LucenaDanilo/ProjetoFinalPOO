#include "Fase.hpp"
#include "Game.hpp"
#include "ObjetoDeJogo.hpp"
#include "Helicoptero.hpp"
#include "Pessoa.hpp"
#include "GalaoGasolina.hpp"
#include "Mensagem.hpp"
#include <iostream>
#include <list>

Fase::Fase() : GameBase(), resgatados(0), sprResgatados("./Sprites/resgatados") ,
    vitoria("./Sprites/Msgs/vitoria.txt"), derrota("./Sprites/Msgs/derrota.txt"), 
    pausa("./Sprites/Msgs/pausa.txt") {
    //
}

Fase::~Fase() {
    for (const auto&obj : listObjJogo) {
        delete obj;
    }
}

ostream &operator<<(ostream &out, Fase &obj) {
    std::cout << Game::screen;
    return out;
}

void Fase::init() {
    system("clear");

    initBackgroud();
    initObjetosJogo();
    drawBackground();
}

void Fase::initBackgroud() {
    // iniciando o background
    background.readPath("./Sprites/pontes");
    ilha1.readPath("./Sprites/ilha");
    ilha2.readPath("./Sprites/ilha");
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
    msg.displayMensagemTela();
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
    msg.setTexto("");
    
    std::string entrada;
    getline(std::cin, entrada);
    system("clear");

    if (entrada[0] == 'p' || entrada[0] == 'P') {
        pausaTela();
    } else if (entrada[0] == 'q' || entrada[0] == 'Q') {
        telaDerrota();
        exit(1);
    } else {
        updateColisao(entrada);
        updateObjetosJogo(entrada);
        incrementaResgatados(entrada);
    }
}

void Fase::pausaTela() const {
    std::string entrada;
    pausa.draw(Game::screen, 18, 55);       
    while (true) {
        show(); 
        getline(std::cin, entrada);
        system("clear");
        if (entrada[0] == 'p' || entrada[0] == 'P') {
            break;
        }
    }
}

void Fase::updateColisao(std::string entrada) {
    auto heroi = listObjJogo.front();

    for (const auto&obj : listObjJogo) {
        if (obj != heroi) {
            if (verificaColisaoObjJogo(*heroi, *obj) && (entrada[0] == 'x' || entrada[0] == 'X')) {
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

void Fase::capturaPessoa(ObjetoDeJogo *heroi, ObjetoDeJogo *obj) {
    heroi->setPeso(heroi->getPeso() + obj->getPeso());
    heroi->incrementaPessoas(1);
    obj->desativa();

    msg.setTexto("[ EMBARQUE REALIZADO ]");
}

void Fase::capturaGalao(ObjetoDeJogo *heroi, ObjetoDeJogo *obj) {
    int gas = heroi->getTanque() + obj->getTanque();
    heroi->setTanque(gas);
    obj->desativa();

    msg.setTexto("[ ABASTECIMENTO FEITO ]");
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

void Fase::show() const {
   std::cout << Game::screen;
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
    int pessoasResgatadas = heroi->getPessoas();

    if (verificaResgate() && (entrada[0] == 'x' || entrada[0] == 'X')) {
        // Resgata a pessoa e a tira do helicoptero
        for (int i = 0; i < pessoasResgatadas; i++) {
            *this << *heroi;
        }

        // Transforma o display no número de pessoas resgatadas
        std::string mensagemResgatados = std::to_string(resgatados);
        sprResgatados.copiaString(mensagemResgatados);

        msg.setTexto("[ RESGATE EFETUADO ]");
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
    std::cout << Game::screen;
}

void Fase::telaDerrota() {
    derrota.draw(Game::screen, 18, 45);
    system("clear");
    std::cout << Game::screen;
}

void Fase::setObjetoJogo(ObjetoDeJogo* obj) {
    listObjJogo.push_front(obj);
}

