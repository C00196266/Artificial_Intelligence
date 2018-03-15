#include <iostream>
#include <vector>
#include "Boid.h"
#include "Pvector.h"
#include "Flock.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

/*
Brief description of Boid Class:
// This file acts as the main for our boids project. Here, we utilize the SFML
// library, import boids and flock classes, and run the program.-
*/

int main()
{
	float boidsSize = 3;
	string action = "flock";

	//Gets the resolution, size, and bits per pixel for the screen of the PC that is running this program.;
	const int window_height = 1080;
	const int window_width = 1920;

	//Having the style of "None" gives a false-fullscreen effect for easier closing and access.
	//No FPS limit of V-sync setting needed for it may cause unnecessary slowdown.
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Lab 6"); 

	window.setFramerateLimit(60);
	
	//Create flock, vector of shapes, and initialize boids
	Flock shoal;
	Flock gullFlock;
	Flock duckFlock;
	vector<sf::CircleShape> herringShapes;
	vector<sf::CircleShape> gullShapes;
	vector<sf::CircleShape> duckShapes;

	sf::RectangleShape water;
	water.setPosition(0, 500);
	water.setSize(sf::Vector2f(1920, 580));
	water.setFillColor(sf::Color(100, 100, 200, 150));

	for (int i = 0; i < 30; i++) //Number of boids is hardcoded for testing pusposes.
	{
		//Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
		Boid herring(960, 750); //Starts all boids in the center of the screen
		sf::CircleShape shape(8,3); //Shape with a radius of 10 and 3 points (Making it a triangle)
		herring.underwater = true;
		herring.predator = false;

		//Changing the Visual Properties of the shape
		//shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
		shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
		shape.setFillColor(sf::Color(255, 60, 20));
		shape.setRadius(boidsSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		shoal.addBoid(herring);
		shoal.noOfPrey++;
		herringShapes.push_back(shape);
	}

	for (int i = 0; i < 6; i++) //Number of boids is hardcoded for testing pusposes.
	{
		//Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
		Boid gull(960, 140); //Starts all boids in the center of the screen
		sf::CircleShape shape(8, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)
		gull.underwater = false;
		gull.predator = true;

		//Changing the Visual Properties of the shape
		//shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
		shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
		shape.setFillColor(sf::Color(160, 160, 160));
		shape.setRadius(boidsSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		gullFlock.addBoid(gull);
		gullShapes.push_back(shape);
	}

	gullFlock.noOfPrey = shoal.noOfPrey;

	for (int i = 0; i < 15; i++) //Number of boids is hardcoded for testing pusposes.
	{
		//Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
		Boid duck(960, 140); //Starts all boids in the center of the screen
		sf::CircleShape shape(8, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)
		duck.underwater = false;
		duck.predator = false;

		//Changing the Visual Properties of the shape
		//shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
		shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
		shape.setFillColor(sf::Color(255, 170, 20));
		shape.setRadius(boidsSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		duckFlock.addBoid(duck);
		duckShapes.push_back(shape);
	}

	// whale
	Boid whale(100, 800, true);
	sf::CircleShape whaleShape(10, 3);
	whale.underwater = true;
	whale.predator = true;

	//Changing visual properties of newly created boid
	whaleShape.setPosition(100, 800);
	whaleShape.setFillColor(sf::Color(0, 0, 255));
	whaleShape.setRadius(6);

	//Adds newly created boid and shape to their respective data structure
	shoal.addBoid(whale);
	herringShapes.push_back(whaleShape);

	while (window.isOpen())
	{	
		//Event used to close program when window is closed
		sf::Event event;
		while (window.pollEvent(event))
		{
			//"close requested" event: we close the window
			//Implemented alternate ways to close the window. (Pressing the escape, X, and BackSpace key also close the program.)
			if ((event.type == sf::Event::Closed) || 
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::Escape) ||
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::BackSpace) ||
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::X))
			{
				window.close();
			}
		}

		//check for mouse click, draws and adds boid to flock if so.
		//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		//{
		//	//Gets mouse coordinates, sets that as the location of the boid and the shape
		//	sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
		//	Boid b(mouseCoords.x, mouseCoords.y, true);
		//	sf::CircleShape shape(10,3);
		//
		//	//Changing visual properties of newly created boid
		//	shape.setPosition(mouseCoords.x, mouseCoords.y);
		//	shape.setFillColor(sf::Color(0, 0, 255));
		//	shape.setRadius(boidsSize);
		//
		//	//Adds newly created boid and shape to their respective data structure
		//	flock.addBoid(b);
		//	shapes.push_back(shape);
		//
		//	//New Shape is drawn
		//	window.draw(shapes[shapes.size()-1]);
		//}
		//Clears previous frames of visualization to not have clutter. (And simulate animation)
		window.clear(sf::Color(255, 255, 255));

		window.draw(water);

		//Draws all of the Boids out, and applies functions that are needed to update.
		for (int i = 0; i < herringShapes.size(); i++)
		{
			window.draw(herringShapes[i]);

			//Cout's removed due to slowdown and only needed for testing purposes
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

			//Matches up the location of the shape to the boid
			herringShapes[i].setPosition(shoal.getBoid(i).location.x, shoal.getBoid(i).location.y);

			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			theta = shoal.getBoid(i).angle(shoal.getBoid(i).velocity);
			herringShapes[i].setRotation(theta);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (herringShapes[i].getPosition().x > window_width)
				herringShapes[i].setPosition(herringShapes[i].getPosition().x - window_width, herringShapes[i].getPosition().y);
			// If boid exits bottom boundary
			if (herringShapes[i].getPosition().y > window_height)
				herringShapes[i].setPosition(herringShapes[i].getPosition().x, herringShapes[i].getPosition().y - window_height);
			// If boid exits left boundary
			if (herringShapes[i].getPosition().x < 0)
				herringShapes[i].setPosition(herringShapes[i].getPosition().x + window_width, herringShapes[i].getPosition().y);
			// If boid exits top boundary
			if (herringShapes[i].getPosition().y < 0)
				herringShapes[i].setPosition(herringShapes[i].getPosition().x, herringShapes[i].getPosition().y + window_height);
		}

		for (int i = 0; i < gullShapes.size(); i++)
		{
			window.draw(gullShapes[i]);

			//Cout's removed due to slowdown and only needed for testing purposes
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

			//Matches up the location of the shape to the boid
			gullShapes[i].setPosition(gullFlock.getBoid(i).location.x, gullFlock.getBoid(i).location.y);

			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			theta = gullFlock.getBoid(i).angle(gullFlock.getBoid(i).velocity);
			gullShapes[i].setRotation(theta);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (gullShapes[i].getPosition().x > window_width)
				gullShapes[i].setPosition(gullShapes[i].getPosition().x - window_width, gullShapes[i].getPosition().y);
			// If boid exits bottom boundary
			if (gullShapes[i].getPosition().y > window_height)
				gullShapes[i].setPosition(gullShapes[i].getPosition().x, gullShapes[i].getPosition().y - window_height);
			// If boid exits left boundary
			if (gullShapes[i].getPosition().x < 0)
				gullShapes[i].setPosition(gullShapes[i].getPosition().x + window_width, gullShapes[i].getPosition().y);
			// If boid exits top boundary
			if (gullShapes[i].getPosition().y < 0)
				gullShapes[i].setPosition(gullShapes[i].getPosition().x, gullShapes[i].getPosition().y + window_height);

			//if (birdShapes.size() < shapes.size()) {
			//	birdShapes[i].setPosition(shapes[i].getPosition().x, birdShapes[i].getPosition().y);
			//}
		}

		for (int i = 0; i < duckShapes.size(); i++)
		{
			window.draw(duckShapes[i]);

			//Cout's removed due to slowdown and only needed for testing purposes
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

			//Matches up the location of the shape to the boid
			duckShapes[i].setPosition(duckFlock.getBoid(i).location.x, duckFlock.getBoid(i).location.y);

			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			theta = duckFlock.getBoid(i).angle(duckFlock.getBoid(i).velocity);
			duckShapes[i].setRotation(theta);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (duckShapes[i].getPosition().x > window_width)
				duckShapes[i].setPosition(duckShapes[i].getPosition().x - window_width, duckShapes[i].getPosition().y);
			// If boid exits bottom boundary
			if (duckShapes[i].getPosition().y > window_height)
				duckShapes[i].setPosition(duckShapes[i].getPosition().x, duckShapes[i].getPosition().y - window_height);
			// If boid exits left boundary
			if (duckShapes[i].getPosition().x < 0)
				duckShapes[i].setPosition(duckShapes[i].getPosition().x + window_width, duckShapes[i].getPosition().y);
			// If boid exits top boundary
			if (duckShapes[i].getPosition().y < 0)
				duckShapes[i].setPosition(duckShapes[i].getPosition().x, duckShapes[i].getPosition().y + window_height);
		}

		//Applies the three rules to each boid in the flock and changes them accordingly.
		shoal.calculateAveragePos();
		shoal.flocking();

		for (int i = 0; i < herringShapes.size(); i++) {
			if (shoal.getBoid(i).alive == false) {
				shoal.flock.erase(shoal.flock.begin() + i);
				shoal.noOfPrey--;
				herringShapes.erase(herringShapes.begin() + i);
				break;
			}
		}

		gullFlock.flocking();
		gullFlock.averagePos = shoal.averagePos;

		duckFlock.formation(0);

		//Updates the window with current values of any data that was modified.
		window.display();

	//This loop continues until window is closed. Continues the process of updating, drawing, rendering the boids, and the window.
	}
	return 0;

}