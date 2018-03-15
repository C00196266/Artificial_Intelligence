#include "Boid.h"
#include "Flock.h"

using namespace std;

// =============================================== //
// ======== Flock Functions from Flock.h ========= //
// =============================================== //

int Flock::getSize()
{
	return flock.size();
}

Boid Flock::getBoid(int i)
{
	return flock[i];
}

void Flock::addBoid(Boid b)
{
	flock.push_back(b);
}

// Runs the run function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::flocking() 
{
	for (int i = 0; i < flock.size(); i++)
	{
		if (flock[i].predator == false) {
			flock[i].run(flock);
		}
		else {
			if (noOfPrey > 0) {
				//calculateAveragePos();
				flock[i].predatorSeek(averagePos, flock);
				if (flock[i].underwater == false) {
					flock[i].run(flock);
				}
			}
		}
	}
}
// Runs the swarm function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::swarming()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].swarm(flock);
	}
}

void Flock::formation(int leader) {
	for (int i = 0; i < flock.size(); i++){
		Pvector sub(0, 0);
		Pvector sum(0, 0);
		int maxDistance = 5;
		Pvector slot;
		Boid target = flock[leader];

		if (i == leader) {
			flock[i].velocity.normalize();
			flock[i].velocity.mulScalar(target.maxSpeed / 4);
			flock[i].update();
			flock[i].borders();
		}
		else {
			sub = sub.subTwoVector(target.location, flock[i].location);
			float distance = sub.magnitude();

			// if the leader wraps around
			if (distance > maxDistance + flock.size() * (maxDistance + 2)) {
				slot = Pvector(target.location.x - 1920, target.location.y);
			}
			else {
				slot = target.location;
			}

			if (i % 2 != 1) {// odd number
				slot.x += i * maxDistance;
				slot.y -= i * maxDistance;
			}
			else { // even number
				slot.x += i * maxDistance;
				slot.y += i * maxDistance;
			}
			sub = sub.subTwoVector(slot, flock[i].location);

			distance = sub.magnitude();

			if (distance > maxDistance) {
				sum = sub;
				sum.normalize();
				sum.mulScalar(flock[i].maxSpeed);
				flock[i].applyForce(sum);
				flock[i].update();
				flock[i].borders();
			}
			else {
				flock[i].velocity = flock[leader].velocity; 
			}
		}
	}
}

void Flock::calculateAveragePos() {
	int noOfPredators = 0;
	Pvector average(0, 0);

	for (int i = 0; i < flock.size(); i++) {
		if (flock[i].predator == false) {
			average.x += flock[i].location.x;
			average.y += flock[i].location.y;
		}
		else {
			noOfPredators++;
		}
	}

	averagePos = Pvector(average.x / (flock.size() - noOfPredators), average.y / (flock.size() - noOfPredators));
}