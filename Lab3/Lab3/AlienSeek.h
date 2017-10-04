#ifndef ALIENSEEK_H
#define ALIENSEEK_H

#include <iostream>
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>

class AlienSeek{
private:
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;

	float m_maxSpeed;

	float m_width;
	float m_height;
	sf::Vector2f m_center;

	float m_angle;

	int m_radius;

	float m_timeToTarget;

	sf::Vector2f m_currentTarget;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Image m_image;

public:
	AlienSeek();
	//AlienSeek(sf::Vector2f maxSpeed);

	void update(sf::Vector2f maxPos, sf::Vector2f target);

	void draw(sf::RenderWindow &window);
};

#endif
