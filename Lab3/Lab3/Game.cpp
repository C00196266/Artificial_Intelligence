#include "Game.h"

Game::Game() : m_alienArriveFast(250), m_alienArriveSlow(100) {

}

void Game::update(sf::Vector2f maxPos, sf::Time time) {
	m_player.update(maxPos);
	//m_alienWander.update(maxPos, m_player.getCenter());
	m_alienSeek.update(maxPos, m_player.getCenter(), time);
	//m_alienFlee.update(maxPos, m_player.getCenter(), time);
	//m_alienPursuit.update(maxPos, m_player.getCenter(), m_player.getVelocity(), time);
	//m_alienArriveFast.update(maxPos, m_player.getCenter(), time);
	//m_alienArriveSlow.update(maxPos, m_player.getCenter(), time);

	//m_alienFlee.update(maxPos, m_player.getCenter(), time);
}

void Game::draw(sf::RenderWindow &window) {
	m_player.draw(window);
	//m_alienWander.draw(window);
	m_alienSeek.draw(window);
	//m_alienFlee.draw(window);
	//m_alienPursuit.draw(window);
	//m_alienArriveFast.draw(window);
	//m_alienArriveSlow.draw(window);

	//m_alienFlee.draw(window);
}