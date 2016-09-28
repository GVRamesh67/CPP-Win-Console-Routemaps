#ifndef Road_H 
#define Road_H
#include <string>
#include "Location.h"
#include "Line.h"
using namespace std;

class Road: public Line{
private:
	Location startLocation;
	Location endLocation;
	string nameRoad;
	float widthRoad;

public:
	//Constructor & Destructor
	Road();
	~Road();
	//set Methods
	void setRoadName(string pName);
	void setRoadWidth(float pWidth);
	void setStartLocation(Location pStartLocation);
	void setEndLocation(Location pEndLocation);
	//get Methods
	string getRoadName();
	float getRoadWidth();
	Location getStartLocation();
	Location getEndLocation();
};
#endif;