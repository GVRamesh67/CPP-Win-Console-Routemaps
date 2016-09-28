#include <iostream>
#include <string>
#include <vector>
#include "Route.h"
#include "Road.h"
#include "Line.h"
using namespace std;

Route::Route() {
	//cout << "Route Object Created" << endl;
}

Route ::~Route() {
	//cout << "Route Object Deleted" << endl;
}

void Route::setRoadsGrouping(std::vector<Road> pRoute) {
	roadsGrouping = pRoute;
}

std::vector<Road> Route::getRoadsGrouping(){
	return roadsGrouping;
}

float Route::getLength(){
	std::vector<Line *> linePointers;
	for (size_t i=0; i<roadsGrouping.vector::size(); i++) {	
		Road road = roadsGrouping[i];		
		Line *linePtr = new Line;			
		linePtr->Line::setStartPoint(road.Road::getStartLocation());
		linePtr->Line::setEndPoint(road.Road::getEndLocation());		
		linePointers.push_back(linePtr);
	}
	return Line::getTotalLength(linePointers);
}