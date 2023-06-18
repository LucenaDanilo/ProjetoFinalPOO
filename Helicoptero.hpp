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
    virtual void draw();

    void setSpriteGas(Sprite*);
    void setSpriteLoud(Sprite*);

    void updateGas();
    void updateLoud();

    inline void setPeso(int c) { carga = c; }
    inline int getPeso() const { return carga;}

private:
    int carga;
    int tanque;
    int pessoas;
    string path;
    Sprite *gas;
    Sprite *loud;

    void drawGas() const;
    void drawLoud() const;

};

#endif