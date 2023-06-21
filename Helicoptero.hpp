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

    void updatePos(string);
    virtual void updateVitoria();
    virtual void updateSprite();
    void updateGas();
    void updateLoud();

    void setTanque(int t);
    void setSpriteGas(Sprite*);
    void setSpriteLoud(Sprite*);
    inline void setPeso(int c) { carga = c; }
    inline void Abastece(int x) { tanque += x; }
    virtual inline void incrementaPessoas(int x) { pessoas += x; }

    inline int getPeso() const { return carga; }
    inline int getTanque() const { return tanque; }
    virtual inline int getPessoas() { return pessoas; }

private:
    int carga, tanque;
    int pessoas, contPassosEsquerda;
    Sprite *gas, *loud;

    void drawGas() const;
    void drawLoud() const;

    inline void incrementaPassosEsquerda() { contPassosEsquerda++; }
    inline void zeraPassosEsquerda() { contPassosEsquerda = 0; }

};

#endif