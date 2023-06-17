#ifndef FASE
#define FASE

#include <list>

#include "GameBase.hpp"
#include "Sprite.hpp"
#include "ObjetoDeJogo.hpp"

using std::list;

class Fase : public GameBase {
public:

    Fase();

    void show();

    virtual void init();
    virtual void update();
    virtual void draw();

    void setObjetoJogo(ObjetoDeJogo*);


private:
    Sprite background;
    Sprite ilha1, ilha2;
    list<ObjetoDeJogo*> listObjJogo;

};

#endif