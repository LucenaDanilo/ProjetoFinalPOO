#ifndef SPRITEBASE
#define SPRITEBASE

class SpriteBase {
public:

    SpriteBase() {}
    ~SpriteBase() {}

    virtual void draw(SpriteBase*, int, int) const = 0;
};

#endif