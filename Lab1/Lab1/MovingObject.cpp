#include "Game.h"

MovingObject::MovingObject() {
	if (!m_image.loadFromFile("square.png")) {
		std::cout << "could not load image from file";
	}
	
	if (!m_texture.loadFromImage(m_image)) {
		std::cout << "could not load texture from image" << std::endl;
	}

	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(1420, 500);
	m_vel = sf::Vector2f(5, 7);
}

void MovingObject::update(sf::Vector2f maxPos) {
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

void MovingObject::draw(sf::RenderWindow &window) {
	window.draw(m_sprite);
}