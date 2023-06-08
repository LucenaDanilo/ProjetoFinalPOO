#ifndef GAME
#define GAME

#include <iostream>

#include "SpriteBase.hpp"
#include "Sprite.hpp"

class Game {
public:

    static void run();

    static SpriteBase *pScreen;
};

#endif
