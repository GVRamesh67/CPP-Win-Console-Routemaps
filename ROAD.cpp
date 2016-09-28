#include <iostream>
#include <string>
#include "Road.h"
#include "Location.h"
using namespace std;

Road::Road(){
	//cout << "Road Object Created" << endl;
}

Road::~Road(){
	//cout << "Road Object Deleted" << endl;
}

void Road::setRoadName(string pName) {
	nameRoad = pName;
}

void Road::setRoadWidth(float pWidth) {
	widthRoad = pWidth;
}

void Road::setStartLocation(Location pStartLocation) {
	Road::startLocation = pStartLocation;
}

void Road::setEndLocation(Location pEndLocation) {
	Road::endLocation = pEndLocation;
}

string Road::getRoadName() {
	return nameRoad;
}

float Road::getRoadWidth() {
	return widthRoad;
}

Location Road::getStartLocation() {
	return Road::startLocation;
}

Location Road::getEndLocation() {
	return Road::endLocation;
}
