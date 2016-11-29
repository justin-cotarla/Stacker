#include "Point.h"

Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}

Point Point::bottomPoint(){
	return Point(this->x, this->y - 1);
}