#ifndef FASE
#define FASE

#include <list>

#include "GameBase.hpp"
#include "Sprite.hpp"
#include "ObjetoDeJogo.hpp"

using std::list;

class Fase : public GameBase {
public:

    Fase( const string &backPath  = "./Sprites/pontes");

    void show();

    virtual void init();
    virtual void update();
    virtual void draw();


private:
    Sprite background;
    list<ObjetoDeJogo*> listObjJogo;

};

#endif