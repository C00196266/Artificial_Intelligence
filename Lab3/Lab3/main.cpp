#include "AlienWander.h"
#include "Game.h"

int main() {
	bool running = true;

	Game game;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Lab 2");

	//window.setFramerateLimit(60.0f);

	sf::Vector2f windowSize(window.getSize().x, window.getSize().y);

	sf::Clock clock;
	sf::Time timer;
	//sf::Int32 msec = timer.asMilliseconds();
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float FPS = 60.0f;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	while (running == true) {
		while (window.isOpen()) {
			sf::Event event;

			while (window.pollEvent(event)) {

				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			timeSinceLastUpdate += clock.restart();

			window.clear(sf::Color::White);

			if (timeSinceLastUpdate > timePerFrame) {
				game.update(windowSize, timeSinceLastUpdate);

				game.draw(window);

				window.display();

				timeSinceLastUpdate = sf::Time::Zero;
			}
		}
	}
}