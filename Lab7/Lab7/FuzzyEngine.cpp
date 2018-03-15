#include "FuzzyEngine.h"

double FuzzyEngine::grade(double value, double x0, double x1) {
	if (value <= 0) {
		return 0;
	}
	else if (value > x1) {
		return 1;
	}
	else {
		return ((value - x0) / (x1 - x0));
	}
}

double FuzzyEngine::triangle(double value, double x0, double x1, double x2) {
	if ((value <= x0) || (value >= x2)) {
		return 0;
	}
	else if (value == x1) {
		return 1;
	}
	else if ((value > x0) && (value < x1)) {
		return ((value - x0) / (x1 - x0));
	}
	else {
		return ((x2 - value) / (x2 - x1));
	}
}

double FuzzyEngine::trapezoid(double value, double x0, double x1, double x2, double x3) {
	if ((value <= x0) || (value >= x2)) {
		return 0;
	}
	else if ((value >= x1) && (value <= x2)) {
		return 1;
	}
	else if ((value > x0) && (value < x1)) {
		return ((value - x0) / (x1 - x0));
	}
	else {
		return ((x3 - value) / (x3 - x2));
	}
}

double FuzzyEngine::and(double a, double b) {
	return std::fmin(a, b);
}

double FuzzyEngine::or(double a, double b) {
	return std::fmax(a, b);
}

double FuzzyEngine::not(double a) {
	return 1.0 - a;
}