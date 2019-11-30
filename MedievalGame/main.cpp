#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <cstdint>
#include <cmath>

constexpr int screenWidth = 336;
constexpr int screenHeight = 240;
constexpr float moveSpeed = 0.875f;
constexpr int walkTime = std::ceil(16.0f / moveSpeed);
constexpr int maxFramerate = 60;

enum class Direction : uint8_t {
	Left, Right, Up, Down
};

enum class TileType : uint8_t {
	Normal, Wall
};

struct Tile {
	const sf::Vector2f atlasPos;
	const TileType type;
};

struct Map {
	unsigned width;
	unsigned height;
	unsigned* data;

	void allocate() {
		data = new unsigned[width * height];
	}

	unsigned& at(int x, int y) const {
		if(x < 0 || y < 0) {
			return data[0];
		}
		return data[y * width + x];
	}

	~Map() {
		delete[] data;
	}
};

struct Camera {
	int x = 0;
	int y = 0;
	float xSub = 0;
	float ySub = 0;
};

struct Player {
	int x = 0;
	int y = 0;
	float xSub = 0;
	float ySub = 0;
	Direction dir = Direction::Down;
	int actionDuration = 0;
};

const Tile tiles[] {
	{{16, 0}, TileType::Normal},
	{{0, 0}, TileType::Wall},
};

std::unordered_map<std::string, Map> maps;
Map* map;
sf::Texture tileAtlas;
sf::Texture playerTexture;
Camera cam;
Player player;



void renderMap(sf::RenderWindow&);
void loadAllMaps();
void setMap(const std::string&);
void limitCameraPos();
void inputs();
void renderPlayer(sf::RenderWindow&);
void moveCameraToPlayer();
void detectCollision(int x, int y);



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
		moveCameraToPlayer();
		limitCameraPos();
		renderMap(window);
		renderPlayer(window);
		//std::cout << player.x << ", " << player.y << '\n';
		std::cout << player.y << ", " << player.ySub << '\n';

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

			quad[0].texCoords = tiles[map->at(j + cam.x, i + cam.y)].atlasPos;
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

void detectCollision(int x, int y) {
	if(x < 0 || y < 0)
		return;
	switch(tiles[map->at(x, y)].type) {
	case TileType::Normal:
		player.actionDuration = walkTime;
		break;
	default:
		break;
	}
}

void inputs() {
	if(player.actionDuration) {
		player.actionDuration--;
		switch(player.dir) {
		case Direction::Up:
			player.ySub -= moveSpeed;
			if(player.ySub < 0.01f) {
				player.ySub += 16.0f;
				player.y--;
			}
		break;
		case Direction::Down:
			player.ySub += moveSpeed;
			if(player.ySub > 15.9f) {
				player.ySub -= 16.0f;
				player.y++;
			}
		break;
		case Direction::Left:
			player.xSub -= moveSpeed;
			if(player.xSub < 0.0f) {
				player.xSub += 16.0f;
				player.x--;
			}
		break;
		case Direction::Right:
			player.xSub += moveSpeed;
			if(player.xSub > 16.0f) {
				player.xSub -= 16.0f;
				player.x++;
			}
		break;
		}
	} else {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player.dir = Direction::Up;
				detectCollision(player.x, player.y - 1);
			}
		} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				player.dir = Direction::Down;
				detectCollision(player.x, player.y + 1);
			}
		} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player.dir = Direction::Left;
				detectCollision(player.x - 1, player.y);
			}
		} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player.dir = Direction::Right;
				detectCollision(player.x + 1, player.y);
			}
		}
	}
}

void renderPlayer(sf::RenderWindow& window) {
	sf::VertexArray playerSprite(sf::Quads, 4);
	playerSprite[0].position = sf::Vector2f((player.x - cam.x) * 16 + player.xSub - cam.xSub, (player.y - cam.y - 1) * 16 + player.ySub - cam.ySub);
	playerSprite[1].position = playerSprite[0].position + sf::Vector2f(16, 0);
	playerSprite[2].position = playerSprite[0].position + sf::Vector2f(16, 32);
	playerSprite[3].position = playerSprite[0].position + sf::Vector2f(0, 32);
	playerSprite[0].texCoords = sf::Vector2f(0, 0);
	playerSprite[1].texCoords = sf::Vector2f(16, 0);
	playerSprite[2].texCoords = sf::Vector2f(16, 32);
	playerSprite[3].texCoords = sf::Vector2f(0, 32);
	window.draw(playerSprite, &playerTexture);
}

void moveCameraToPlayer() {
	cam.x = player.x - screenWidth / 32;
	cam.y = player.y - screenHeight / 32;
	cam.xSub = player.xSub;
	cam.ySub = player.ySub;
}
