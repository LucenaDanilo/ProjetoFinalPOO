#ifndef PESSOA
#define PESSOA

#include "ObjetoDeJogo.hpp"

class Pessoa : public ObjetoDeJogo {
public:
    Pessoa(int, int);

    virtual void init() {}
    virtual void update() {}
    virtual void update(string) {}
    virtual void draw() const ;

    virtual int getPeso() const { return peso;}
    virtual void setPeso(int p) {peso = p;}

private:
    int peso;

};

#endif