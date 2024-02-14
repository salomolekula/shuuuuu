#include <string>
#include "Circle.h"

Circle::Circle(int x, int y, int r, std::string colour)
: x(x), y(y), r(r), colour(colour) {}

int Circle::getX()
{
	return x;
}

int Circle::getY()
{
	return y;
}

int Circle::getR()
{
	return r;
}

double Circle::circleLengthCount()
{
	return 3.1415 * 2 * r;
}

double Circle::circleSqCount()
{
	return 3.1415 * r * r;
}