#include "Helicoptero.hpp"

Helicoptero::Helicoptero() : ObjetoDeJogo() , carga(0), tanque(100), pessoas(0) {
    x = 10;
    y = 10;
    ativo = false;
    objSprite->setPath("./Sprites/helicoptero");
}

