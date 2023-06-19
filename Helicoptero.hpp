#ifndef HELICOPTERO
#define HELICOPTERO

#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"

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

    void updateSprite();
    void updatePos(string);
    void updateGas();
    void updateLoud();

    inline void setPeso(int c) { carga = c; }
    inline int getPeso() const { return carga; }

    inline void setTanque(int t) { tanque = t; }
    inline int getTanque() const { return tanque; }

private:
    int carga, tanque;
    int pessoas, contSprite;
    string path;
    Sprite *gas, *loud;

    void drawGas() const;
    void drawLoud() const;

};

#endif