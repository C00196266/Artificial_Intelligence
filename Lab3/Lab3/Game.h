#ifndef GAME_H
#define GAME_H

#include "AlienWander.h"
#include "AlienSeek.h"
#include "AlienFlee.h"
#include "AlienPursuit.h"
#include "Player.h"

class Game {
private:
	AlienWander m_alienWander;
	AlienSeek m_alienSeek;
	AlienFlee m_alienFlee;
	AlienPursuit m_alienPursuit;
	Player m_player;

public:
	Game();
	
	void update(sf::Vector2f maxPos);

	void draw(sf::RenderWindow &window);
};

#endif
