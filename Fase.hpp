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

    void updateColisao(std::string) const;
    void updateObjetosJogo(string) const;

    bool verificaFim();

    void setObjetoJogo(ObjetoDeJogo*);
    void incrementaResgatados(std::string);
    inline int getResgatados() const { return resgatados; }

    void capturaPessoa(ObjetoDeJogo*, ObjetoDeJogo*) const;
    void capturaGalao(ObjetoDeJogo*, ObjetoDeJogo*) const;

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