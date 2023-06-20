#ifndef OBJETODEJOGO
#define OBJETODEJOGO

#include "SpriteBase.hpp"
#include "GameBase.hpp"
#include "vector"

using std::string;

class ObjetoDeJogo : public GameBase {
public:
    ObjetoDeJogo(const string&);

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void update(string) = 0;
    virtual void draw() const = 0;

    virtual int getPeso() const = 0;
    virtual void setPeso(int) = 0;

    virtual void setTanque( int ) = 0;
    virtual int getTanque() const = 0;
    virtual inline void incrementaPessoas( int ) = 0;
    virtual inline int getPessoas() = 0;
    virtual void updateVitoria() = 0;

    bool colideCom(const ObjetoDeJogo&) const;
    void moveTo(int, int);
    void ativa();
    void desativa();
    void updateSprite();

    void setPosX(int);
    void setPosY(int);
    void setSprite(const string&);
    void setNSprites(int n) {nSprites = n;}
    inline void setId(std::string s) { id = s; }

    int getPosX() const;
    int getPosY() const;
    bool getAtivo() const;
    int getIndSprite() const;
    int getNSprites() const;
    inline string getId() const { return id; }

    void insereSprite(std::string);
    inline Sprite* getSprite() const { return spritesObj[indSprite]; }
    
protected:
    SpriteBase* objSprite;

private:
    std::string id;
    int x, y;
    bool ativo;
    std::vector<Sprite*> spritesObj;
    int indSprite, nSprites;
};

#endif