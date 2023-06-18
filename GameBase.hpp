#ifndef GAMEBASE
#define GAMEBASE

class GameBase {
public:
    GameBase() {}
    ~GameBase() {}

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;

};

#endif