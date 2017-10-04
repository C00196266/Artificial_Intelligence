#include "Game.h"

Game::Game() {

}

void Game::update(sf::Vector2f maxPos) {
	m_movingObject.update(maxPos);
	m_player.update(maxPos);
}

void Game::draw(sf::RenderWindow &window) {
	m_player.draw(window);
	m_movingObject.draw(window);
}