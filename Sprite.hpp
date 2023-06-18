#ifndef SPRITE
#define SPRITE

#include <iostream>
#include <vector>

#include "SpriteBase.hpp"

using std::string, std::vector;

class Sprite : public SpriteBase {
public:

    Sprite( string = "");
    //Sprite( const Sprite& ) {}

    virtual void init() {}
    virtual void update();
    virtual void draw() {}
    virtual void draw(Sprite&, int, int) const;

    virtual void show() const;

    void limpaScreen(const Sprite&);

    virtual void setPath( string );
    void setH() const {}
    void setW() const {}

    void copiaString(const string&);

private:
    vector<string> vecString;
    int h, w;
};

#endif