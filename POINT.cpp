#include "Point.h"
#include <iostream>
using namespace std;


Point::Point(){
	//cout << "Point Object Created" << endl;
}

Point::~Point() {
	//cout << "Point Object Deleted" << endl;
}

void Point::setXValue(float pX_Value){
	X_Value = pX_Value;
}

void Point::setYValue(float pY_Value){
	Y_Value = pY_Value;
}

float Point::getXValue(){
	return X_Value;
}

float Point::getYValue(){
	return Y_Value;
}