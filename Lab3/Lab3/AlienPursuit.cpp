#include "AlienPursuit.h"

AlienPursuit::AlienPursuit() {
	if (!m_image.loadFromFile("Alien Pursuit.png")) {
		std::cout << "could not load image from file";
	}

	if (!m_texture.loadFromImage(m_image)) {
		std::cout << "could not load texture from image" << std::endl;
	}

	m_sprite.setTexture(m_texture);

	m_pos = sf::Vector2f(1220, 700);
	m_sprite.setPosition(m_pos);

	m_width = m_sprite.getLocalBounds().width;
	m_height = m_sprite.getLocalBounds().height;

	m_center = sf::Vector2f(m_pos.x + (m_width / 2), m_pos.y + (m_height / 2));

	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

	m_orientation = 0;
	m_maxRotation = 30.0f;
	m_rotation = 0;

	m_maxAcceleration = 50.0f;
	m_linearAccel = sf::Vector2f(0, 0);
	m_angularAccel = sf::Vector2f(0, 0);

	m_radius = 100;

	m_timeToTarget = 2;
	
	m_maxTimePrediction = 50;

	m_vel = sf::Vector2f(0, 0);

	m_currentTarget = sf::Vector2f(0, 0);
	m_maxSpeed = 120.0f;
}

void AlienPursuit::update(sf::Vector2f maxPos, sf::Vector2f target, sf::Vector2f targetVel, sf::Time time) {
	if (target != m_currentTarget) {
		m_currentTarget = target;
	}

	if (targetVel != m_currentTargetVel) {
		m_currentTargetVel = targetVel;
	}

	m_direction = m_currentTarget - m_center;
	
	float distance = sqrt((m_direction.x * m_direction.x) + (m_direction.y * m_direction.y));
	
	m_speed = sqrt((m_vel.x * m_vel.x) + (m_vel.y * m_vel.y));
	
	if (m_speed <= distance / m_maxTimePrediction) {
		m_timePrediction = m_maxTimePrediction;
	}
	else {
		m_timePrediction = distance / m_speed;
	}

	m_currentTarget = m_currentTarget + m_currentTargetVel * m_timePrediction;

	m_linearAccel = (m_currentTarget - m_center) / m_timeToTarget;

	float magnitudeAccel = sqrt((m_linearAccel.x * m_linearAccel.x) + (m_linearAccel.y * m_linearAccel.y));

	if (magnitudeAccel > m_maxAcceleration) {
		m_linearAccel = normalise(m_linearAccel) * m_maxAcceleration;
	}

	m_vel += m_linearAccel * time.asSeconds();

	float magnitudeVel = sqrt((m_vel.x * m_vel.x) + (m_vel.y * m_vel.y));

	if (magnitudeVel > m_maxSpeed) {
		m_vel = normalise(m_vel) * m_maxSpeed;
	}

	//////////////////////////////////////////////////////
	float orientation = atan2(m_vel.x, m_vel.y);

	// ALIGN //
	m_rotation = orientation - m_orientation;

	// map to range ???
	if (m_rotation > m_maxRotation) {
		m_rotation = m_maxRotation;
	}
	else if (m_rotation < -m_maxRotation) {
		m_rotation = -m_maxRotation;
	}

	// ???

	float rotationSize = abs(m_rotation);

	float targetRotation = m_maxRotation * rotationSize;

	float angular = (targetRotation - m_rotation) / 2;

	float angularaAbs = abs(angular);

	if (angularaAbs > 4) {
		angular /= angularaAbs * 4;
	}

	// END ALIGN //

	/////////////////////////////////////////////////////////////////

	m_pos += m_vel * time.asSeconds();
	m_orientation += angular * time.asSeconds();

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

	m_center = sf::Vector2f(m_pos.x + (m_width / 2), m_pos.y + (m_height / 2));

	m_sprite.setRotation((m_orientation * 180 / 3.14) + 90);

	m_sprite.setPosition(m_pos);
}

void AlienPursuit::draw(sf::RenderWindow &window) {
	window.draw(m_sprite);
}

sf::Vector2f AlienPursuit::normalise(sf::Vector2f v) {
	float magnitude = sqrt((v.x* v.x) + (v.y * v.y));

	return (v / magnitude);
}