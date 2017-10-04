#ifndef GAME_H
#define GAME_H

#include "MovingObject.h"
#include "Player.h"

class Game {
private:
	MovingObject m_movingObject;
	Player m_player;

public:
	Game();
	
	void update(sf::Vector2f maxPos);

	void draw(sf::RenderWindow &window);
};

#endif
