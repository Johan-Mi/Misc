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

void renderMap(const sf::RenderWindow&);

int main() {
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Medieval Game", sf::Style::Fullscreen);

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

void renderMap(const sf::RenderWindow& window) {
	for(int i = 0; i < (screenHeight + 15) / 16 + 1; i++) {
		for(int j = 0; j < (screenWidth + 15) / 16 + 1; j++) {
			sf::VertexArray quad(sf::Quads, 4);
			quad[0].position = sf::Vector2f(j * 16, i * 16);
			quad[1].position = quad[0].position + sf::Vector2f(16, 0);
			quad[2].position = quad[0].position + sf::Vector2f(16, 16);
			quad[3].position = quad[0].position + sf::Vector2f(0, 16);
			window.draw(quad);
		}
	}
}
