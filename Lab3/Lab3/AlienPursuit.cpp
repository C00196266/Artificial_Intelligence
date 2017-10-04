#include "AlienPursuit.h"

AlienPursuit::AlienPursuit() {
	if (!m_image.loadFromFile("Alien Pursuit.png")) {
		std::cout << "could not load image from file";
	}

	if (!m_texture.loadFromImage(m_image)) {
		std::cout << "could not load texture from image" << std::endl;
	}

	m_sprite.setTexture(m_texture);

	m_pos = sf::Vector2f(1220, 700);
	m_sprite.setPosition(m_pos);

	m_width = m_sprite.getLocalBounds().width;
	m_height = m_sprite.getLocalBounds().height;

	m_center = sf::Vector2f(m_pos.x + (m_width / 2), m_pos.y + (m_height / 2));

	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

	m_angle = 0;

	m_radius = 100;

	m_timeToTarget = 2;
	
	m_maxTimePrediction = 50;

	m_vel = sf::Vector2f(0, 0);

	m_currentTarget = sf::Vector2f(0, 0);
	m_maxSpeed = 5.0f;
}

void AlienPursuit::update(sf::Vector2f maxPos, sf::Vector2f target, sf::Vector2f targetVel) {
	if (target != m_currentTarget) {
		m_currentTarget = target;
	}

	if (targetVel != m_currentTargetVel) {
		m_currentTargetVel = targetVel;
	}

	m_direction = m_currentTarget - m_center;

	float distance = sqrt((m_direction.x * m_direction.x) + (m_direction.y * m_direction.y));

	m_speed = sqrt((m_vel.x * m_vel.x) + (m_vel.y * m_vel.y));

	if (m_speed <= distance / m_maxTimePrediction) {
		m_timePrediction = m_maxTimePrediction;
	}
	else {
		m_timePrediction = distance / m_speed;
	}

	m_currentTarget = m_currentTarget + m_currentTargetVel * m_timePrediction;

	m_vel = m_currentTarget - m_center;
	
	float magnitudeVel = sqrt((m_vel.x * m_vel.x) + (m_vel.y * m_vel.y));
	
	if (magnitudeVel > m_radius) {
		m_vel = m_vel / magnitudeVel;
	
		m_vel *= m_maxSpeed;
	
		if (magnitudeVel > 0) {
			m_angle = atan2(-m_currentTarget.x, m_currentTarget.y);
		}
	}
	
	else {
		m_vel = m_vel / m_timeToTarget;
	
		if (magnitudeVel > m_maxSpeed) {
			m_vel = m_vel / magnitudeVel;
			m_vel *= m_maxSpeed;
		}
	
		if (magnitudeVel > 0) {
			m_angle = atan2(-m_currentTarget.x, m_currentTarget.y);
		}
	}

	m_pos += m_vel;

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

	m_center = sf::Vector2f(m_pos.x + (m_width / 2), m_pos.y + (m_height / 2));

	m_sprite.setRotation((atan2(m_vel.y, m_vel.x) * 180 / 3.14) + 90);

	m_sprite.setPosition(m_pos);
}

void AlienPursuit::draw(sf::RenderWindow &window) {
	window.draw(m_sprite);
}