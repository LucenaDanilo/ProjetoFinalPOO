#ifndef GALAOGASOLINA
#define GALAOGASOLINA

#include "ObjetoDeJogo.hpp"

class GalaoGasolina : public ObjetoDeJogo {
public:
    GalaoGasolina();

    virtual void init();
    virtual void update() {}
    virtual void update(string);
    virtual void updateVitoria() {}
    virtual void draw() const;

    virtual int getPeso() const { return peso; }
    virtual void setPeso(int p) { peso = p; }

    virtual void setTanque(int t) { tanque = t; }
    virtual int getTanque() const { return tanque;; }

    virtual inline void incrementaPessoas(int x) {}
    virtual inline int getPessoas() {return 0;}

private:
    int tanque;
    int peso;
};

#endif
