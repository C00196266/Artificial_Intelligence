#ifndef PLAYER_H
#define PLAYER_H

#include "MovingObject.h"

class Player : public MovingObject {
private:
	bool allowKeyPress;
	
public:
	Player();

	void update(sf::Vector2f maxPos);
};

#endif
