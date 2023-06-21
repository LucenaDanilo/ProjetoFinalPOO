#ifndef FASE
#define FASE

#include <list>

#include "GameBase.hpp"
#include "Sprite.hpp"
#include "ObjetoDeJogo.hpp"
#include "Mensagem.hpp"

using std::list, std::string;

class Fase : public GameBase {
    friend ostream &operator<<(ostream &out, Fase &obj);

    Fase &operator<<(ObjetoDeJogo &obj) {
        resgatados += 1;
        obj.incrementaPessoas(-1);
        obj.setPeso(obj.getPeso() - 68);
        return *this;
    }

public:

    Fase();
    ~Fase();

    virtual void init();
    virtual void draw() const;
    virtual void update();

    void show() const;
    
    void initBackgroud();
    void initObjetosJogo();

    void drawBackground() const;
    void drawObjetosJogo() const;

    void updateColisao(std::string);
    void updateObjetosJogo(string) const;

    bool verificaFim();

    void setObjetoJogo(ObjetoDeJogo*);
    void incrementaResgatados(std::string);
    inline int getResgatados() const { return resgatados; }

    void capturaPessoa(ObjetoDeJogo*, ObjetoDeJogo*);
    void capturaGalao(ObjetoDeJogo*, ObjetoDeJogo*);

private:
    Sprite background, sprResgatados;
    Sprite ilha1, ilha2, vitoria, derrota, pausa;
    list<ObjetoDeJogo*> listObjJogo;
    int resgatados;
    Mensagem msg;

    bool verificaColisaoObjJogo(ObjetoDeJogo&, ObjetoDeJogo&) const;
    bool verificaColisaoRescueBase() const;
    bool verificaResgate() const;
    bool verificaVitoria() const;
    bool verificaDerrota() const;

    void telaVitoria();
    void telaDerrota();

    void pausaTela() const;
};

#endif