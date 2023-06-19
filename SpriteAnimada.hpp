#ifndef SPRITEANIMADA
#define SPRITEANIMADA

#include <vector>

#include "SpriteBase.hpp"
#include "Sprite.hpp"

class SpriteAnimada : public SpriteBase {
public:
    SpriteAnimada(string s = "") : SpriteBase(s) {}

    virtual void init() {}
    virtual void update() {}
    virtual void draw() const {}
    virtual void draw(Sprite&, int, int) const {}

    virtual void show() const {}
    virtual void setPath( string ) {}

    virtual inline int getH() const {}
    virtual inline int getW() const {}

private:
    std::vector<Sprite> vecSprites;
};

#endif