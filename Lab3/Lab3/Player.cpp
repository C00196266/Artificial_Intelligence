#include "Player.h"

Player::Player() {
	if (!m_image.loadFromFile("Player Ship.png")) {
		std::cout << "could not load image from file";
	}

	if (!m_texture.loadFromImage(m_image)) {
		std::cout << "could not load texture from image" << std::endl;
	}

	m_sprite.setTexture(m_texture);

	m_pos = sf::Vector2f(500, 500);
	m_sprite.setPosition(500, 500);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

	m_width = m_sprite.getLocalBounds().width;
	m_height = m_sprite.getLocalBounds().height;
	
	m_center = sf::Vector2f(m_pos.x + (m_width / 2), m_pos.y + (m_height / 2));

	m_orientation = 0;
	m_speed = 0;

	m_vel = sf::Vector2f(0, 0);
}

void Player::update(sf::Vector2f maxPos) {
	if (allowKeyPress == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			allowKeyPress = false;

			if (m_speed < m_maxSpeed) {
				m_speed++;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			allowKeyPress = false;

			if (m_speed > 0) {
				m_speed--;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (m_speed > 0) {
				m_orientation += 0.05f;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (m_speed > 0) {
				m_orientation -= 0.05f;
			}
		}
	}

	else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			allowKeyPress = true;
		}
	}

	if (m_speed > 0) {
		m_vel = sf::Vector2f(cos(m_orientation) * m_speed, sin(m_orientation) * m_speed);
		m_pos += m_vel;
		m_center = sf::Vector2f(m_pos.x + (m_width / 2), m_pos.y + (m_height / 2));
	}

	m_sprite.setRotation((m_orientation * 180 / 3.14) + 90);

	if (m_pos.x > (maxPos.x + m_sprite.getLocalBounds().width / 2)) {
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

void Player::draw(sf::RenderWindow &window) {
	window.draw(m_sprite);
}

sf::Vector2f Player::getCenter() {
	return m_center;
}

sf::Vector2f Player::getVelocity() {
	return m_vel;
}

float Player::getOrientation() {
	return m_orientation;
}