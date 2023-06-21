#ifndef PESSOA
#define PESSOA

#include "ObjetoDeJogo.hpp"

class Pessoa : public ObjetoDeJogo {
public:
    Pessoa(int, int);

    // Métodos virtuais de GameBase e ObjJogo
    virtual void init();
    virtual void update() {}
    virtual void update(string);
    virtual void updateVitoria() {}
    virtual void draw() const ;
    virtual inline void incrementaPessoas(int x) {}
    virtual inline int getPessoas() {return 0;}

    // Getters
    virtual int getPeso() const { return peso;}
    virtual void setPeso(int p) {peso = p;}

    // Setters
    virtual void setTanque(int t) {}
    virtual int getTanque() const { return 1; }

private:
    int peso;

};

#endif