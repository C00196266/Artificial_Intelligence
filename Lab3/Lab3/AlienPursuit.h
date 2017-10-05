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

	float m_maxAcceleration;
	sf::Vector2f m_linearAccel;
	float m_magnitudeAccel;

	float m_width;
	float m_height;
	sf::Vector2f m_center;

	float m_orientation;
	float m_rotation;
	float m_maxRotation;
	float m_targetRotation;
	float m_rotationSize;

	float m_angularAccel;
	float m_angularAbs;

	float m_timeToTarget;
	float m_maxTimePrediction;
	float m_timePrediction;

	sf::Vector2f m_currentTarget;
	sf::Vector2f m_currentTargetVel;
	float m_magnitudeVel;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Image m_image;

public:
	AlienPursuit();

	void update(sf::Vector2f maxPos, sf::Vector2f target, sf::Vector2f targetVel, sf::Time time);

	void draw(sf::RenderWindow &window);

	sf::Vector2f normalise(sf::Vector2f v);
};

#endif
