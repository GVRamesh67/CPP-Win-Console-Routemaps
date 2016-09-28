#ifndef Point_H 
#define Point_H

class Point {
protected:
	float X_Value;
	float Y_Value;

public:
	//Constructor and Destructor
	Point();
	~Point();
	//set Methods
	void setXValue(float pX_Value);
	void setYValue(float pY_Value);
	//get Methods
	float getXValue();
	float getYValue();
};
#endif;