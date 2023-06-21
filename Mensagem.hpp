#ifndef MENSAGEM
#define MENSAGEM

#include "Sprite.hpp"
#include "Game.hpp"

class Mensagem {
public:
    Mensagem() : texto("./Sprites/Msgs/default.txt") {}

    void displayMensagemTela() const {
        texto.draw(Game::screen, 4, 68);
    }

    void setTexto(std::string s) {texto.copiaString(s);}
    
private:
    Sprite texto;

};

#endif