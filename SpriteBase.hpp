#ifndef SPRITEBASE
#define SPRITEBASE

#include <iostream>

using std::string;

class SpriteBase {
public:

    SpriteBase( string p ) : path (p) {}
    ~SpriteBase() {}

    virtual void desenharEm(SpriteBase&, int, int) const = 0;
    virtual void show() const = 0;

    
    string path;
    
};

#endif