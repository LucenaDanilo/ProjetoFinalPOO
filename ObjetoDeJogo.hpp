#ifndef OBJETODEJOGO
#define OBJETODEJOGO

#include "SpriteBase.hpp"
#include "GameBase.hpp"

using std::string;

class ObjetoDeJogo : public GameBase {
public:
    ObjetoDeJogo(const string&);

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void update(string) = 0;
    virtual void draw() = 0;

    bool colideCom(const ObjetoDeJogo&) const;
    void moveTo(int, int);
    void ativa();
    void desativa();

    void setPosX(int);
    void setPosY(int);
    void setSprite(const string&);

    int getPosX() const;
    int getPosY() const;
    bool getAtivo() const;

protected:
    SpriteBase* objSprite;

private:
    int x, y;
    bool ativo;
};

#endif