#ifndef Line_H 
#define Line_H
#include <vector>
#include "Point.h"

class Line {
protected:	
	Point startPoint;
	Point endPoint;

public:
	//Constructor & Destructor
	Line();
	~Line();
	
	//set Methods
	void setStartPoint(Point stPt);
	void setEndPoint(Point enPt);

	//get Methods
	Point getStartPoint();
	Point getEndPoint();
	
	float length(); //returns the length of the line
	static float getTotalLength(std::vector<Line *> lines); //returns the total length of the list of Lines
};
#endif;