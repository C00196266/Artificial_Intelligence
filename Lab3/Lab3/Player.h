#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>

class Player {
private:
	bool allowKeyPress;

	sf::Vector2f m_pos;
	sf::Vector2f m_vel;

	float m_width;
	float m_height;
	sf::Vector2f m_center;

	float m_angle;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Image m_image;

	int m_speed;
	const int m_maxSpeed = 15;
	
public:
	Player();

	void draw(sf::RenderWindow &window);

	void update(sf::Vector2f maxPos);

	sf::Vector2f getCenter();

	sf::Vector2f getVelocity();
};

#endif
