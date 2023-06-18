#ifndef SPRITEBASE
#define SPRITEBASE

#include <iostream>
#include "GameBase.hpp"

using std::string;
class Sprite;

class SpriteBase : public GameBase {
public:

    SpriteBase( string p ) : path (p) {}
    ~SpriteBase() {}

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;
    virtual void draw(Sprite&, int, int) const = 0;

    virtual void show() const = 0;
    virtual void setPath( string ) = 0;

    virtual inline int getH() const = 0;
    virtual inline int getW() const = 0;

protected:
    string path;
};

#endif