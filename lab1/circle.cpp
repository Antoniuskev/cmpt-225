#include <iostream>
#include "circle.h"
using namespace std;


	//Default constructor: constructor 
	//Description: create default cicle
	Circle::Circle()
	{
		x = 0;
		y = 0;
		r = 10;
	}

	//Constructor:
	//Description: 	changes value of x,y and r to given value
	Circle::Circle( int newx, int newy, double newr)
	{
		x = newx;
		y = newy;

		if (newr < 0)
			r = newr;
		else
			r = 10;	
	}


	//Move the cirle position by given horizontal and vertical distance
	void Circle::move(int horiz, int vert)
	{
		x = x + horiz;
		y = y + vert;
	}

	// change r to given number
	void Circle::setRadius( double newr )
	{
		r = newr;
	}

	//getters
	int Circle::getX() const
	{
		return x;
	}

	int Circle::getY() const
	{
		return y;
	}

	double Circle::getRadius() const 
	{
		return r;
	}

	double Circle::getArea() 
	{
		double area = 3.14159265359 * getRadius() * getRadius();
		return area;
	}

	void Circle::displayCircle() const
	{
		cout<< endl << "radius = " << getRadius();
		cout<< " at point X = " << getX();
		cout<< ", Y = "<< getY();
	}
