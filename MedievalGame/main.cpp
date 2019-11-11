#include <SFML/Graphics.hpp>

constexpr int screenWidth = 256;
constexpr int screenHeight = 240;

struct Tile {
	int atlasX;
	int atlasY;
};

constexpr Tile tiles[] {
	{0, 0},
};

int* map;
int mapWidth;
int mapHeight;

void renderMap(sf::RenderWindow&);
void loadAllMaps();

sf::Texture tileAtlas;

int main() {
	tileAtlas.loadFromFile("Graphics/tileAtlas.png");
	sf::VideoMode screenRes = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(screenRes, "Medieval Game", sf::Style::Fullscreen);
	window.setView(sf::View(sf::FloatRect(0, 0, screenWidth, screenHeight)));

	loadAllMaps();

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
			quad[0].texCoords = sf::Vector2f(0, 0);
			quad[1].texCoords = quad[0].texCoords + sf::Vector2f(16, 0);
			quad[2].texCoords = quad[0].texCoords + sf::Vector2f(16, 16);
			quad[3].texCoords = quad[0].texCoords + sf::Vector2f(0, 16);
			window.draw(quad, &tileAtlas);
		}
	}
}

void loadAllMaps() {
	std::if mapNames();
}
