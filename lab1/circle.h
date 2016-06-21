//Descriptiom : this class models is circle
//Author: Kevin Antoniuc

class Circle
{
private:
	int x;  //can be negative
	int y;	// can be negative
	double r; // radius must greater than 0
public:
	//Default constructor
	Circle();	//has no parameters
	//Constractor with given vales
	Circle( int newx,int newy, double newr );

	void move(int horiz, int vert);
	void setRadius(double r);

	//getters for retunint information about the cirgle 
	int getX() const; 
	int getY() const;
	double getRadius() const;
	double getArea();


	//Display method that prints the circle's x,y, and r.
	void displayCircle() const;

	//bool intersect(Circle C);

};