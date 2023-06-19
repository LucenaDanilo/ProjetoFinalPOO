#ifndef PESSOA
#define PESSOA

#include "ObjetoDeJogo.hpp"

class Pessoa : public ObjetoDeJogo {
public:
    Pessoa(int, int);

    virtual void init();
    virtual void update() {}
    virtual void update(string);
    virtual void draw() const ;

    virtual int getPeso() const { return peso;}
    virtual void setPeso(int p) {peso = p;}

    virtual void setTanque(int t) {}
    virtual int getTanque() const { return 1; }

    virtual inline void incrementaPessoas(int x) {}
    virtual inline int getPessoas() {return 0;}

private:
    int peso;

};

#endif