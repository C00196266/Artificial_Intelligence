#include "Player.h"

Player::Player() {
	if (!m_image.loadFromFile("circle.png")) {
		std::cout << "could not load image from file";
	}

	if (!m_texture.loadFromImage(m_image)) {
		std::cout << "could not load texture from image" << std::endl;
	}

	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(500, 500);
	m_vel = sf::Vector2f(6, 6);
}

void Player::update(sf::Vector2f maxPos) {
	if (allowKeyPress == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			allowKeyPress = false;

			if (m_vel.x < 20 && m_vel.y < 20) {
				m_vel += sf::Vector2f(1, 1);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			allowKeyPress = false;

			if (m_vel.x > 0 && m_vel.y > 0) {
				m_vel -= sf::Vector2f(1, 1);
			}
		}
	}

	else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			allowKeyPress = true;
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

	m_sprite.setPosition(m_pos);
}