#ifndef ALIENFLEE_H
#define ALIENFLEE_H

#include <iostream>
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>

class AlienFlee {
private:
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;

	float m_maxSpeed;

	float m_maxAcceleration;
	sf::Vector2f m_linearAccel;
	sf::Vector2f m_angularAccel;

	float m_width;
	float m_height;
	sf::Vector2f m_center;

	float m_orientation;
	float m_rotation;
	float m_maxRotation;

	float m_timeToTarget;

	sf::Vector2f m_currentTarget;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Image m_image;

public:
	AlienFlee();

	void update(sf::Vector2f maxPos, sf::Vector2f target, sf::Time time);

	void draw(sf::RenderWindow &window);

	sf::Vector2f normalise(sf::Vector2f v);
};

#endif
