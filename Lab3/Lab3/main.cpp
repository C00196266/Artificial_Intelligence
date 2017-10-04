#include "AlienWander.h"
#include "Game.h"

int main() {
	bool running = true;

	Game game;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Lab 2");

	window.setFramerateLimit(60.0f);

	sf::Vector2f windowSize(window.getSize().x, window.getSize().y);

	while (running == true) {
		while (window.isOpen()) {
			sf::Event event;

			while (window.pollEvent(event)) {

				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.clear(sf::Color::White);

			game.update(windowSize);

			game.draw(window);

			window.display();
		}
	}
}