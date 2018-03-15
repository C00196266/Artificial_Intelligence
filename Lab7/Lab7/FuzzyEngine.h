#pragma once

#include <iostream>
#include <cmath>

class FuzzyEngine {
public:
	FuzzyEngine() {}

	double grade(double value, double x0, double x1);
	double triangle(double value, double x0, double x1, double x2);
	double trapezoid(double value, double x0, double x1, double x2, double x3);
	double and(double a, double b);
	double or(double a, double b);
	double not(double a);
};