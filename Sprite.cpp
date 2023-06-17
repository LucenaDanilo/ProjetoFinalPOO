#include "Sprite.hpp"
#include "SpriteBase.hpp"
#include "Game.hpp"

#include <fstream>

using std::ifstream, std::getline, std::cout, std::endl;

Sprite::Sprite( string path ) : SpriteBase(path) , w(0), h(0) {

    if (path != "")
        setPath(path);
}

void Sprite::setPath( string p ) {
    path = p;

    ifstream file(path);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            h++;
            vecString.push_back(line);
        }
        file.close();
    }
    else {
        cout << "Erro ao abrir o arquivo: " << path << endl;
    }
}

void Sprite::show() const {
    for (const string& line : this->vecString) {
        cout << line << endl;
    }
}

// Sprite::Sprite( const Sprite &alvo ) : SpriteBase(path) , w(0), h(0) {
//     int c = 0;
//     for (const string& line : this->vecString) {
//         alvo.vecString[c++] = line;
//     }
// }

void Sprite::draw(Sprite& screen, int x, int y) const {
    int countX = 0, countY = 0;
    for (const string& line : this->vecString) {
        countY = 0;
        for (const char& carac : line) {
            screen.vecString[x + countX][y + countY++] = carac;
        }
        countX++;
    }

}