#ifndef ALIENPURSUIT_H
#define ALIENPURSUIT_H

#include <iostream>
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>

class AlienPursuit {
private:
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Vector2f m_direction;

	float m_speed;
	float m_maxSpeed;

	float m_width;
	float m_height;
	sf::Vector2f m_center;

	float m_angle;

	int m_radius;

	float m_timeToTarget;
	float m_maxTimePrediction;
	float m_timePrediction;

	sf::Vector2f m_currentTarget;
	sf::Vector2f m_currentTargetVel;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Image m_image;

public:
	AlienPursuit();

	void update(sf::Vector2f maxPos, sf::Vector2f target, sf::Vector2f targetVel);

	void draw(sf::RenderWindow &window);
};

#endif
