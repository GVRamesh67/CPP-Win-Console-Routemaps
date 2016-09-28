#include "Point.h"
#include "Location.h"
#include <iostream>
#include <string>
using namespace std;

Location::Location(){
	//cout << "Location Object Created" << endl;
}

Location::~Location() {
	//cout << "Location Object Deleted" << endl;
}

void Location::setLocationName(string pName){
	nameLocation = pName;
}

string Location::getLocationName() {
	return nameLocation;
}