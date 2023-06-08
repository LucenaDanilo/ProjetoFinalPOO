#include "Sprite.hpp"
#include "SpriteBase.hpp"

#include <fstream>

using std::ifstream, std::getline, std::cout, std::endl;

Sprite::Sprite( string path ) : SpriteBase() ,path(path), w(0), h(0) {

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

void Sprite::draw(SpriteBase*, int, int) const {
    for (const string& line : vecString) {
        cout << line << endl;
    }
}