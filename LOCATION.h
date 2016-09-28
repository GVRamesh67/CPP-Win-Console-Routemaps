#ifndef Location_H 
#define Location_H
#include <string>
#include "Point.h"
using namespace std;

class Location: public Point{
private:
	string nameLocation;

public:
	//Constructor & Destructor	
	Location();
	~Location();

	//set Method
	void setLocationName(string pName);
	
	// get Method
	string getLocationName();
};
#endif;