#ifndef OBJETODEJOGO
#define OBJETODEJOGO

#include "SpriteBase.hpp"
#include "GameBase.hpp"

class ObjetoDeJogo : public GameBase {
public:
    ObjetoDeJogo();

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

    bool colideCom(const ObjetoDeJogo&) const;
    void moveTo(int, int);
    void ativa();
    void desativa();

    void setPosX();
    void setPosY();

    int getPosX() const;
    int getPosY() const;

protected:
    SpriteBase* objSprite;
    int x, y;
    bool ativo;
};

#endif