#ifndef PESSOA
#define PESSOA

#include "ObjetoDeJogo.hpp"

class Pessoa : public ObjetoDeJogo {
public:
    Pessoa(int, int);

    virtual void init() {}
    virtual void update() {}
    virtual void update(string) {}
    virtual void draw();

private:
    int peso;

};

#endif