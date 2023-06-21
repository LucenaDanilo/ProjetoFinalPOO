#ifndef OBJETODEJOGO
#define OBJETODEJOGO

#include "SpriteBase.hpp"
#include "GameBase.hpp"
#include "vector"

using std::string;

class ObjetoDeJogo : public GameBase {

public:
    ObjetoDeJogo(const string&);
    ~ObjetoDeJogo();

    // Métodos virtuais de GameBase
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void update(string) = 0;
    virtual void draw() const = 0;

    // Métodos virtuais gerais aos ObjetosDeJogo
    virtual int getPeso() const = 0;
    virtual void setPeso(int) = 0;
    virtual void setTanque( int ) = 0;
    virtual int getTanque() const = 0;
    virtual void incrementaPessoas( int ) = 0;
    virtual int getPessoas() = 0;
    virtual void updateVitoria() = 0;

    bool colideCom(const ObjetoDeJogo&) const;
    void moveTo(int, int);
    virtual void updateSprite();
    
    // Getters
    int getPosX() const { return x; }
    int getPosY() const { return y; }
    int getIndSprite() const { return indSprite; }
    int getNSprites() const { return nSprites; }
    bool getAtivo() const { return ativo; }
    inline string getId() const { return id; }
    inline bool getSentidoDireita() const { return direita; }
    inline Sprite* getSprite() const { return spritesObj[indSprite]; }

    // Setters
    void setSprite(const string&);
    void insereSprite(std::string);
    inline void setPosX(int x) { this->x = x; }
    inline void setPosY(int y) { this->y = y; }
    inline void setNSprites(int n) { nSprites = n;}
    inline void setIndSprites(int x) { indSprite = x;}
    inline void setId(std::string s) { id = s; }
    inline void ativa()    { ativo = true; }
    inline void desativa() { ativo = false; }
    inline void sentidoDireita()  { direita = true; }
    inline void sentidoEsquerda() { direita = false; }
    
private:
    std::string id;
    int x, y;
    bool ativo, direita;
    std::vector<Sprite*> spritesObj;
    int indSprite, nSprites;
    SpriteBase* objSprite;
};

#endif