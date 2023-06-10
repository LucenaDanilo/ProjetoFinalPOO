#ifndef SPRITE
#define SPRITE

#include <iostream>
#include <vector>

#include "SpriteBase.hpp"

using std::string, std::vector;

class Sprite : public SpriteBase {
public:

    Sprite( string );
    //Sprite( const Sprite& ) {}

    virtual void desenharEm(SpriteBase&, int, int) const {}
    virtual void draw(Sprite&, int, int) const;
    virtual void show() const;

private:
    vector<string> vecString;
    int h, w;
};

#endif