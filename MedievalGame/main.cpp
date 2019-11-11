#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

constexpr int screenWidth = 256;
constexpr int screenHeight = 240;

struct Tile {
	const sf::Vector2f atlasPos;
};

const Tile tiles[] {
	{{0, 0}},
	{{16, 0}},
};

struct Map {
	unsigned width;
	unsigned height;
	unsigned* data;

	void allocate() {
		data = new unsigned[width * height];
	}

	unsigned& operator()(int x, int y) {
		return data[x * width + y];
	}

	~Map() {
		delete[] data;
	}
};

std::unordered_map<std::string, Map> maps;

Map* map;

void renderMap(sf::RenderWindow&);
void loadAllMaps();

sf::Texture tileAtlas;

int main() {
	tileAtlas.loadFromFile("Graphics/tileAtlas.png");
	sf::VideoMode screenRes = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(screenRes, "Medieval Game", sf::Style::Fullscreen);
	window.setView(sf::View(sf::FloatRect(0, 0, screenWidth, screenHeight)));

	loadAllMaps();

	map = &maps["map1"];

	while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
			else if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape)
					window.close();
			}
        }

		renderMap(window);

        window.display();
    }

    return 0;
}

void renderMap(sf::RenderWindow& window) {
	for(int i = 0; i < (screenHeight + 15) / 16 + 1; i++) {
		for(int j = 0; j < (screenWidth + 15) / 16 + 1; j++) {
			sf::VertexArray quad(sf::Quads, 4);
			quad[0].position = sf::Vector2f(j * 16, i * 16);
			quad[1].position = quad[0].position + sf::Vector2f(16, 0);
			quad[2].position = quad[0].position + sf::Vector2f(16, 16);
			quad[3].position = quad[0].position + sf::Vector2f(0, 16);

			quad[0].texCoords = tiles[(*map)(j, i)].atlasPos;
			quad[1].texCoords = quad[0].texCoords + sf::Vector2f(16, 0);
			quad[2].texCoords = quad[0].texCoords + sf::Vector2f(16, 16);
			quad[3].texCoords = quad[0].texCoords + sf::Vector2f(0, 16);
			window.draw(quad, &tileAtlas);
		}
	}
}

void loadAllMaps() {
	std::ifstream mapNames("mapNames");
	std::string currentName;
	while(mapNames >> currentName) {
		std::ifstream currentMap("Maps/" + currentName, std::ios::in | std::ios::binary);
		std::vector<unsigned char> contents((std::istreambuf_iterator<char>(currentMap)), std::istreambuf_iterator<char>());
		currentMap.close();
		maps[currentName].width = *(unsigned*)&contents[0];
		maps[currentName].height = *(unsigned*)&contents[4];
		maps[currentName].allocate();
		for(int i = 0; i < maps[currentName].width * maps[currentName].height; i++)
			maps[currentName].data[i] = *(unsigned*)&contents[4 * i + 8];
		std::clog << "Loaded map: " << currentName << "\nWidth: " << maps[currentName].width << "\nHeight: " << maps[currentName].height << '\n';
	}
	mapNames.close();
}
