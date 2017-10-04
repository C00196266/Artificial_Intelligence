#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include <iostream>
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class MovingObject {
protected:
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Image m_image;

public:
	MovingObject();

	void update(sf::Vector2f maxPos);

	void draw(sf::RenderWindow &window);
};

#endif
