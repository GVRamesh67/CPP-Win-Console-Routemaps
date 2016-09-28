#ifndef Route_H 
#define Route_H
#include <vector>
#include "Road.h"
using namespace std;

class Route{
private:
	std::vector<Road> roadsGrouping;

public:
	//Constructor & Destructor
	Route();
	~Route();
	//set Method
	void setRoadsGrouping(std::vector<Road> pRoute);
	//get Method
	std::vector<Road> getRoadsGrouping();

	float getLength(); //returns the length of the route
};
#endif;