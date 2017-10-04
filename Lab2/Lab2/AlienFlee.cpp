#include "AlienFlee.h"

AlienFlee::AlienFlee() {
	if (!m_image.loadFromFile("Alien Flee.png")) {
		std::cout << "could not load image from file";
	}

	if (!m_texture.loadFromImage(m_image)) {
		std::cout << "could not load texture from image" << std::endl;
	}

	m_sprite.setTexture(m_texture);

	m_pos = sf::Vector2f(800, 600);
	m_sprite.setPosition(m_pos);

	m_width = m_sprite.getLocalBounds().width;
	m_height = m_sprite.getLocalBounds().height;

	m_center = sf::Vector2f(m_pos.x + (m_width / 2), m_pos.y + (m_height / 2));

	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

	m_angle = 0;

	m_vel = sf::Vector2f(0, 0);

	m_currentTarget = sf::Vector2f(0, 0);
	m_maxSpeed = 2.5f;
}

void AlienFlee::update(sf::Vector2f maxPos, sf::Vector2f target) {
	if (target != m_currentTarget) {
		m_currentTarget = target;
	}

	m_vel = m_center - m_currentTarget;

	float magnitudeVel = sqrt((m_vel.x * m_vel.x) + (m_vel.y * m_vel.y));

	if (magnitudeVel > 5) {
		m_vel = sf::Vector2f(m_vel.x / 20, m_vel.y / 20);

		if (magnitudeVel > m_maxSpeed) {
			m_vel = sf::Vector2f(m_vel.x / magnitudeVel, m_vel.y / magnitudeVel);
			m_vel *= m_maxSpeed;
		}

		if (magnitudeVel > 0) {
			m_angle = atan2(-m_vel.x, m_vel.y);
		}
	}
	//else {

	//}

	m_vel = sf::Vector2f(-sin(m_angle) * m_maxSpeed, cos(m_angle) * m_maxSpeed);

	m_pos += m_vel;
	m_center = sf::Vector2f(m_pos.x + (m_width / 2), m_pos.y + (m_height / 2));

	m_sprite.setRotation((atan2(m_vel.y, m_vel.x) * 180 / 3.14) + 90);

	if (m_pos.x > maxPos.x) {
		m_pos.x = 0 - m_sprite.getLocalBounds().width;
	}
	else if (m_pos.x < (0 - m_sprite.getLocalBounds().width)) {
		m_pos.x = maxPos.x;
	}

	if (m_pos.y > maxPos.y) {
		m_pos.y = 0 - m_sprite.getLocalBounds().height;
	}
	else if (m_pos.y < (0 - m_sprite.getLocalBounds().height)) {
		m_pos.y = maxPos.y;
	}

	m_sprite.setPosition(m_pos);
}

void AlienFlee::draw(sf::RenderWindow &window) {
	window.draw(m_sprite);
}