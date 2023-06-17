#ifndef HELICOPTERO
#define HELICOPTERO

#include "ObjetoDeJogo.hpp"

class Helicoptero : public ObjetoDeJogo {
public:
    Helicoptero();

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

private:
    int carga;
    int tanque;
    int pessoas;
};

#endif