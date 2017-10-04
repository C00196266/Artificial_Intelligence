#ifndef ALIENWANDER_H
#define ALIENWANDER_H

#include <iostream>
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>

class AlienWander {
private:
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;

	float m_width;
	float m_height;
	sf::Vector2f m_center;

	float m_angle;

	float m_timeToTarget;

	float m_maxSpeed;

	sf::Vector2f m_currentTarget;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Image m_image;
public:
	AlienWander();

	void update(sf::Vector2f maxPos, sf::Vector2f target);

	void draw(sf::RenderWindow &window);
};

#endif
