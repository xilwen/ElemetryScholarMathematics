#include "PolygonArea.h"


PolygonArea::PolygonArea(){}
PolygonArea::~PolygonArea(){}

void  PolygonArea::PolygonAreaCalculating(vector<short> x, vector<short> y)
{
	int count = x.size();
		double  area = 0.0;
		for (int i = 0; i<count-1; ++i)
			area += PolygonArea::cross(x[i], y[i], x[i + 1], y[i + 1]);

		cout << "The Area: " << fabs(area) / 2.0;
		
}

double PolygonArea::cross(short x1, short y1, short x2, short y2)
{
	return x1* y2 - x2 * y1;
}