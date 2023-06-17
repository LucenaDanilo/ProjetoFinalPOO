#include "ObjetoDeJogo.hpp"

ObjetoDeJogo::ObjetoDeJogo() : GameBase() {}

bool ObjetoDeJogo::colideCom(const ObjetoDeJogo&) const { return true;}
void ObjetoDeJogo::moveTo(int, int) {}
void ObjetoDeJogo::ativa() {}
void ObjetoDeJogo::desativa() {}

void ObjetoDeJogo::setPosX() {}
void ObjetoDeJogo::setPosY() {}

int ObjetoDeJogo::getPosX() const {return 1;}
int ObjetoDeJogo::getPosY() const {return 1;}