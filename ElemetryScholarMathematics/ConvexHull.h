#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <iostream>
#include <vector>
using std::vector;
class ConvexHull
{
public:
	ConvexHull() = delete;
	ConvexHull(vector<short> x1, vector<short> y1);
	
	void sort();
	void swap(int i,int j);



	int  Andrew_monotone_chain();
	double cross(int o, int a, int b);
	bool compare(int a, int b);

	inline vector<short> getX(){ return x; }
	inline vector<short> getY(){ return y; }

private:
	vector<short> x;
	vector<short> y;

	vector<short> x0;
	vector<short> y0;

};

#endif