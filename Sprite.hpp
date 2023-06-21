#ifndef SPRITE
#define SPRITE

#include <iostream>
#include <vector>

#include "SpriteBase.hpp"

using std::string, std::vector, std::ostream, std::endl, std::cout;

class Sprite : public SpriteBase {

    friend ostream &operator<<(ostream &out, Sprite &obj);

public:

    Sprite( string = "");

    // Métodos virtuais de GameBase
    virtual void init() {}
    virtual void update() {}
    virtual void draw() const {}

    // Sobrecarga em draw
    virtual void draw(Sprite&, int, int) const;

    virtual void show() const;
    virtual void readPath( string );
    void limpaScreen(const Sprite&);
    void copiaString(const string&);

    // Setters
    inline void setH(int h) { this->h = h; }
    inline void setW(int w) {this->w = w; }

    // Getters
    virtual inline int getH() const { return h; }
    virtual inline int getW() const { return w; }

private:
    vector<string> vecString;
    int h, w;
};

#endif