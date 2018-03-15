#include <time.h>
#include <vector>
#include "SFML\Main.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "FuzzyEngine.h"

void setupEnemy(std::vector<sf::RectangleShape> &enemies, double size, double range);
void deployArmy(std::vector<sf::RectangleShape> &army, double deploy);
void drawArmies(sf::RenderWindow &window, std::vector<sf::RectangleShape> &army, std::vector<sf::RectangleShape> &enemies);

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Lab 7");

	sf::Clock clock;
	sf::Time timer;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float FPS = 60.0f;
	const sf::Time timePerFrame = sf::seconds(1.0f / FPS);

	srand(time(NULL));

	FuzzyEngine fuzzyEngine;

	bool running = true;

	double size = rand() % 15;
	double tiny;
	double small;
	double moderate;
	double large;

	double range = rand() % 40;
	double close;
	double medium;
	double far;

	double low;
	double mMedium;
	double high;
	double deploy;

	bool changed = false;
	int counter = 0;

	std::vector<sf::RectangleShape> army;
	std::vector<sf::RectangleShape> enemies;

	setupEnemy(enemies, size, range);

	while (running == true) {
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}

			timeSinceLastUpdate += clock.restart();

			window.clear(sf::Color::White);

			if (timeSinceLastUpdate > timePerFrame) {
				if (changed == false) {
					tiny = fuzzyEngine.triangle(size, -10, 0, 10);
					small = fuzzyEngine.trapezoid(size, 2.5, 10, 15, 20);
					moderate = fuzzyEngine.trapezoid(size, 15, 20, 25, 30);
					large = fuzzyEngine.grade(size, 25, 30);

					close = fuzzyEngine.triangle(range, -30, 0, 30);
					medium = fuzzyEngine.trapezoid(range, 10, 30, 50, 70);
					far = fuzzyEngine.grade(range, 50, 70);

					low = fuzzyEngine.or(fuzzyEngine. and (medium, tiny), fuzzyEngine.and(medium, small));
					mMedium = fuzzyEngine.and(close, tiny);
					high = fuzzyEngine.and(close, fuzzyEngine.not(medium));

					deploy = (low * 10 + mMedium * 30 + high * 50) / (low + mMedium + high);
					std::cout << "Deploy: " << deploy << std::endl;

					deployArmy(army, deploy);

					changed = true;
				}
				else {
					if (counter < 200) {
						counter++;
					}
					else {
						counter = 0;
						changed = false;
						size = rand() % 15;
						range = rand() % 40;
						setupEnemy(enemies, size, range);
					}
				}

				drawArmies(window, army, enemies);

				window.display();

				timeSinceLastUpdate = sf::Time::Zero;
			}

			if (running == false)
			{
				window.close();
			}
		}
	}

	return 0;
}

void setupEnemy(std::vector<sf::RectangleShape> &enemies, double size, double range) {
	enemies.clear();

	for (int i = 0; i < size; i++) {
		sf::RectangleShape rect;
		rect.setPosition(50 + (30 * i), 75 + (range * 15));
		rect.setSize(sf::Vector2f(20, 20));
		rect.setFillColor(sf::Color::Red);

		enemies.push_back(rect);
	}
}

void deployArmy(std::vector<sf::RectangleShape> &army, double deploy) {
	army.clear();

	for (int i = 0; i < deploy; i++) {
		sf::RectangleShape rect;
		rect.setPosition(50 + (30 * i), 50);
		rect.setSize(sf::Vector2f(20, 20));
		rect.setFillColor(sf::Color::Blue);

		army.push_back(rect);
	}
}

void drawArmies(sf::RenderWindow &window, std::vector<sf::RectangleShape> &army, std::vector<sf::RectangleShape> &enemies) {
	for (int i = 0; i < army.size(); i++) {
		window.draw(army.at(i));
	}

	for (int i = 0; i < enemies.size(); i++) {
		window.draw(enemies.at(i));
	}
}