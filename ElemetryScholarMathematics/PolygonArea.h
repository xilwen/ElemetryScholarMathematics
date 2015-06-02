//written by GODKING 

#ifndef POLYGONAREA_H
#define POLYGONAREA_H
#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;

class PolygonArea
{
public:
	PolygonArea();
	~PolygonArea();
	double cross(short x1,short y1,short x2,short y2);

	void PolygonAreaCalculating(vector<short> x, vector<short> y);

};

#endif