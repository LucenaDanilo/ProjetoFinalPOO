#ifndef HELICOPTERO
#define HELICOPTERO

#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"

using std::string;

class Helicoptero : public ObjetoDeJogo {
public:
    Helicoptero();

    virtual void init() {}
    virtual void update() {}
    virtual void update(string);
    virtual void draw();

private:
    int carga;
    int tanque;
    int pessoas;
    string path;
    Sprite *gas;
    Sprite *loud;

    void drawGas() const;
    void drawLoad() const;

};

#endif