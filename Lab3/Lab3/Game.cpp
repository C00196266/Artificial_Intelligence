#include "Game.h"

Game::Game() {

}

void Game::update(sf::Vector2f maxPos) {
	m_player.update(maxPos);
	m_alienWander.update(maxPos, m_player.getCenter());
	m_alienSeek.update(maxPos, m_player.getCenter());
	m_alienFlee.update(maxPos, m_player.getCenter());
	m_alienPursuit.update(maxPos, m_player.getCenter(), m_player.getVelocity());
}

void Game::draw(sf::RenderWindow &window) {
	m_player.draw(window);
	m_alienWander.draw(window);
	m_alienSeek.draw(window);
	m_alienFlee.draw(window);
	m_alienPursuit.draw(window);
}