#include "Point.h"
#include "Line.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

Line::Line(){
	//cout << "Line object created" << endl;
}

Line::~Line() {
	//cout << "Line object deleted" << endl;
}

void Line::setStartPoint(Point stPt){
	startPoint = stPt;
}

void Line::setEndPoint(Point enPt) {
	endPoint = enPt;
}

Point Line::getStartPoint(){
	return startPoint;
}

Point Line::getEndPoint(){
	return endPoint;
}

float Line::length() {
	float xvalStart = startPoint.Point::getXValue();
	float xvalEnd = endPoint.Point::getXValue();
	float yvalStart = startPoint.Point::getYValue();
	float yvalEnd = endPoint.Point::getYValue();
	float lengthLine = sqrt(((xvalStart-xvalEnd)*(xvalStart-xvalEnd)) + ((yvalStart - yvalEnd)*(yvalStart - yvalEnd)));
	return lengthLine;	
}

float Line::getTotalLength(vector<Line *> lines) {
	float tempTotalLength = 0.0;
	for (size_t i =0; i < lines.vector::size(); i++) {		
		tempTotalLength = tempTotalLength + lines[i]->Line::length();
	}
	return tempTotalLength;
}; 