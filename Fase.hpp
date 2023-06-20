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
    ~Fase();

    void show();

    virtual void init();
    virtual void draw() const;
    virtual void update();
    
    void initBackgroud();
    void initObjetosJogo();

    void drawBackground() const;
    void drawObjetosJogo() const;

    void updateColisao() const;
    void updateObjetosJogo(string) const;

    bool verificaFim();

    void setObjetoJogo(ObjetoDeJogo*);
    void incrementaResgatados();
    inline int getResgatados() const { return resgatados; }

private:
    Sprite background, sprResgatados;
    Sprite ilha1, ilha2, vitoria, derrota;
    list<ObjetoDeJogo*> listObjJogo;
    int resgatados;

    bool verificaColisaoObjJogo(ObjetoDeJogo&, ObjetoDeJogo&) const;
    bool verificaColisaoRescueBase() const;
    bool verificaResgate() const;
    bool verificaVitoria() const;
    bool verificaDerrota() const;

    void telaVitoria();
    void telaDerrota();
};

#endif