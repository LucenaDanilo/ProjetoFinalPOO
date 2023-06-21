#ifndef MENU
#define MENU

#include "Game.hpp"
#include "iostream"

using std::ostream;

class Sprite;

class Menu {

    friend ostream &operator<<(ostream &out, Menu &obj) {
        std::cout << obj.screenMenu;
        return out;
    }

public:

    Menu() : screenMenu("./Sprites/Menu/screenMenu"), screenMenuLimpa("./Sprites/Menu/screenMenu") , sprHeli("./Sprites/Menu/heliFrente1") , 
        selecaoEsq("./Sprites/Menu/selecionadoEsquerdo") , selecaoDir("./Sprites/Menu/selecionadoDireito"), indPos(0), startGame(false) {
        //
        posSelecoes[0] = 25;
        posSelecoes[1] = 27;
        posSelecoes[2] = 29;
    }

    virtual void init() {
        system("clear");
        sprHeli.draw(screenMenu, 5, 60);
        selecaoEsq.draw(screenMenu, 25, 62);
        selecaoDir.draw(screenMenu, 25, 89);
    }

    virtual void draw() {
        sprHeli.draw(screenMenu, 5, 60);
        selecaoEsq.draw(screenMenu, posSelecoes[indPos], 62);
        selecaoDir.draw(screenMenu, posSelecoes[indPos], 89);
    }

    virtual void update() {
        screenMenu.limpaScreen(screenMenuLimpa);
        
        std::string entrada;
        getline(std::cin, entrada);
        system("clear");

        if (entrada[0] == 's' || entrada[0] == 'S') {
            if (indPos < 2) {
                indPos++;
            } 
        } else if (entrada[0] == 'W' || entrada[0] == 'w') {
            if (indPos > 0) {
                indPos--;
            }
        } else if (entrada[0] == 'x' || entrada[0] == 'X') {
            if (indPos == 0) {
                setStartGame();
            } else if (indPos == 1) {
                //
            } else {
                exit(0);
            }
        }
    }

    inline void setStartGame() {
        startGame = true;
    }

    inline bool getStartGame() { return startGame; }

private:
    std::vector<Sprite*> sprHelis;
    Sprite screenMenu, screenMenuLimpa , screenHelp;
    Sprite sprHeli, selecaoEsq, selecaoDir;
    int posSelecoes[3], indPos;
    bool startGame;
};

#endif