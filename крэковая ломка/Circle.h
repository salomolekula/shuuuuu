#ifndef CIRCLE_H 
#define CIRCLE_H 
#include <string>

class Circle
{

private:
	int x = 0;
	int y = 0;
	int r = 0;
	std::string colour = "black";

public:

	Circle(int x, int y, int r, std::string colour);

	int getX();

	int getY();

	int getR();

	double circleLengthCount();
	double circleSqCount();
};
#endif
