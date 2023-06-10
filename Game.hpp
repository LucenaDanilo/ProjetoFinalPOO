#ifndef GAME
#define GAME

#include <iostream>

#include "SpriteBase.hpp"
#include "Sprite.hpp"

class Game {
public:

    static void run();

    static Sprite screen;
private:
    
    static Sprite screenLimpa;
};

#endif
