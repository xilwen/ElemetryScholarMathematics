#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <iostream>
#include <vector>
using std::vector;
class ConvexHull
{
public:
<<<<<<< HEAD
	ConvexHull() = delete;
	ConvexHull(vector<short> x1, vector<short> y1);
=======
	ConvexHull();
	ConvexHull(vector<short> x1, vector<short> y1);//send the original points to vector x0, vector y0
	
	void  Andrew_monotone_chain();// use this function to do Convex-Hull and save data to vector x, vector y
>>>>>>> origin/master
	

	// The following functions are to help ---- Andrew_monotone_chain()
	void sort(); // sort vector x0, vector y0   from left (down) to right (up)
	void swap(int i, int j);

	double cross(int o, int a, int b);
	bool compare(int a, int b);

	// These are used to send the final data 
	inline vector<short> getX(){ return x; }
	inline vector<short> getY(){ return y; }

private:
	vector<short> x;
	vector<short> y;

	vector<short> x0;
	vector<short> y0;

};

#endif