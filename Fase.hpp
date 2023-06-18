#ifndef FASE
#define FASE

#include <list>

#include "GameBase.hpp"
#include "Sprite.hpp"
#include "ObjetoDeJogo.hpp"

using std::list, std::string;

class Fase : public GameBase {
public:

    Fase();

    void show();

    virtual void init();
    virtual void update();
    virtual void draw();

    void initBackgroud();
    void initObjetosJogo();

    void drawBackground() const;
    void drawObjetosJogo() const;
    
    void updateColisao() const;
    void updateObjetosJogo(string) const;

    void setObjetoJogo(ObjetoDeJogo*);

private:
    Sprite background;
    Sprite ilha1, ilha2;
    list<ObjetoDeJogo*> listObjJogo;
    int resgatados;

};

#endif