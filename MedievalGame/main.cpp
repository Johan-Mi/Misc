#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

constexpr int screenWidth = 320;
constexpr int screenHeight = 240;
constexpr float moveSpeed = 2.0f;
constexpr int maxFramerate = 60;

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
		return data[y * width + x];
	}

	~Map() {
		delete[] data;
	}
};

std::unordered_map<std::string, Map> maps;

Map* map;

sf::Texture tileAtlas;

struct Camera {
	int x = 0;
	int y = 0;
	float xSub = 0;
	float ySub = 0;
} cam;

enum class Direction {
	Left, Right, Up, Down
};

struct Player {
	int x = 3;
	int y = 3;
	float xSub = 0;
	float ySub = 0;
	Direction dir = Direction::Down;
} player;

sf::Texture playerTexture;



void renderMap(sf::RenderWindow&);
void loadAllMaps();
void setMap(const std::string&);
void limitCameraPos();
void inputs();
void renderPlayer(sf::RenderWindow&);



int main() {
	sf::VideoMode screenRes = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(screenRes, "Medieval Game", sf::Style::Fullscreen);
	window.setView(sf::View(sf::FloatRect(0, 0, screenWidth, screenHeight)));
	window.setFramerateLimit(maxFramerate);
	window.setVerticalSyncEnabled(true);

	tileAtlas.loadFromFile("Graphics/tileAtlas.png");
	playerTexture.loadFromFile("Graphics/Sprites/player.png");

	loadAllMaps();
	setMap("map1");

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

		inputs();
		limitCameraPos();
		renderMap(window);
		renderPlayer(window);

		window.display();
	}

	return 0;
}



void renderMap(sf::RenderWindow& window) {
	for(int i = 0; i < screenHeight / 16 + (cam.y != map->height - screenHeight / 16); i++) {
		for(int j = 0; j < screenWidth / 16 + (cam.x != map->width - screenWidth / 16); j++) {
			sf::VertexArray quad(sf::Quads, 4);
			quad[0].position = sf::Vector2f(j * 16 - cam.xSub, i * 16 - cam.ySub);
			quad[1].position = quad[0].position + sf::Vector2f(16, 0);
			quad[2].position = quad[0].position + sf::Vector2f(16, 16);
			quad[3].position = quad[0].position + sf::Vector2f(0, 16);

			quad[0].texCoords = tiles[(*map)(j + cam.x, i + cam.y)].atlasPos;
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
		map = &maps[currentName];
		map->width = *(unsigned*)&contents[0];
		map->height = *(unsigned*)&contents[4];
		map->allocate();
		for(int i = 0; i < map->width * map->height; i++)
			map->data[i] = *(unsigned*)&contents[4 * i + 8];
		std::clog << "Loaded map: " << currentName << "\nWidth: " << map->width << "\nHeight: " << map->height << '\n';
	}
	mapNames.close();
}

void setMap(const std::string& name) {
	map = &maps[name];
}

void limitCameraPos() {
	if(cam.x < 0) {
		cam.x = 0;
		cam.xSub = 0.0f;
	} else if(cam.x >= map->width - screenWidth / 16) {
		cam.x = map->width - screenWidth / 16;
		cam.xSub = 0.0f;
	}
	if(cam.y < 0) {
		cam.y = 0;
		cam.ySub = 0.0f;
	} else if(cam.y >= map->height - screenHeight / 16) {
		cam.y = map->height - screenHeight / 16;
		cam.ySub = 0.0f;
	}
}

void inputs() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		cam.xSub -= moveSpeed;
		if(cam.xSub < 0.0f) {
			cam.xSub += 16.0f;
			cam.x--;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		cam.xSub += moveSpeed;
		if(cam.xSub > 16.0f) {
			cam.xSub -= 16.0f;
			cam.x++;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		cam.ySub -= moveSpeed;
		if(cam.ySub < 0.0f) {
			cam.ySub += 16.0f;
			cam.y--;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		cam.ySub += moveSpeed;
		if(cam.ySub > 16.0f) {
			cam.ySub -= 16.0f;
			cam.y++;
		}
	}
}

void renderPlayer(sf::RenderWindow& window) {
	sf::VertexArray playerSprite(sf::Quads, 4);
	playerSprite[0].position = sf::Vector2f((player.x - cam.x) * 16 + player.xSub - cam.xSub, (player.y - cam.y - 1) * 16 + player.ySub - cam.ySub);
	playerSprite[1].position = playerSprite[0].position + sf::Vector2f(16, 0);
	playerSprite[2].position = playerSprite[0].position + sf::Vector2f(16, 16);
	playerSprite[3].position = playerSprite[0].position + sf::Vector2f(0, 16);
	playerSprite[0].texCoords = sf::Vector2f(0, 0);
	playerSprite[1].texCoords = sf::Vector2f(16, 0);
	playerSprite[2].texCoords = sf::Vector2f(16, 32);
	playerSprite[3].texCoords = sf::Vector2f(0, 32);
	window.draw(playerSprite, &playerTexture);
}
