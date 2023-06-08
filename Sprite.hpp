#ifndef SPRITE
#define SPRITE

#include <iostream>
#include <vector>

#include "SpriteBase.hpp"

using std::string, std::vector;

class Sprite : public SpriteBase {
public:

    Sprite( string );

    virtual void draw(SpriteBase*, int, int) const;

private:
    string path;
    vector<string> vecString;
    int h, w;

};

#endif