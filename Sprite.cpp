#include "Sprite.hpp"
#include "SpriteBase.hpp"
#include "Game.hpp"

#include <fstream>

using std::ifstream, std::getline, std::cout, std::endl;

Sprite::Sprite( string path ) : SpriteBase(path) , w(0), h(0) {

    if (path != "")
        readPath(path);
}

ostream &operator<<(ostream &out, Sprite &obj) {
    for (const string& line : obj.vecString) {
        cout << line << endl;
    }
    return out;
}

void Sprite::readPath( string p ) {
    setPath(p);
    int max = 0;

    ifstream file(p);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            h++;
            if (line.length() > max) {
                max = line.length();
            }
            vecString.push_back(line);
        }
        file.close();
    }
    else {
        cout << "Erro ao abrir o arquivo: " << p << endl;
    }
    w = max + 1;
}

void Sprite::show() const {
    for (const string& line : this->vecString) {
        cout << line << endl;
    }
}

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

void Sprite::limpaScreen(const Sprite &screenLimpa) {
    int c = 0;

    for (const auto &i : screenLimpa.vecString) {
        this->vecString[c++] = i;
    }
}

void Sprite::copiaString(const string &s) {
    this->vecString[0] = s;
}