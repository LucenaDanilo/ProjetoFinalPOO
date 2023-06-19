#ifndef HELICOPTERO
#define HELICOPTERO

#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"
#include <vector>

using std::string;

class Helicoptero : public ObjetoDeJogo {
public:
    Helicoptero();

    virtual void init();
    virtual void update() {}
    virtual void update(string);
    virtual void draw() const;

    void setSpriteGas(Sprite*);
    void setSpriteLoud(Sprite*);

    void updatePos(string);
    void updateGas();
    void updateLoud();

    inline void setPeso(int c) { carga = c; }
    inline int getPeso() const { return carga; }

    inline void setTanque(int t) { tanque = t; }
    inline int getTanque() const { return tanque; }

    virtual inline void incrementaPessoas(int x) { pessoas += x; }
    virtual inline int getPessoas() { return pessoas; }

private:
    int carga, tanque;
    int pessoas;
    Sprite *gas, *loud;

    void drawGas() const;
    void drawLoud() const;

};

#endif