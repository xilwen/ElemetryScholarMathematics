//written by qqwerfdsa930

#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include <vector>
#include <iostream>
#include <string>

class ConvexHull
{
public:
	ConvexHull() = delete;
	ConvexHull(const std::vector<short>, const std::vector<short>); // (x , y)

	//short getx(short a);	// Get ConvexHull x, y
	//short gety(short a);

	bool compare(short a, short b);
	double cross(short o, short a, short b);
	std::vector<short> findConvexHull(std::vector<short> a);
	
	int toUI(int line, std::string[]); //(How many lines to print, texts to print) for DEBUG

	~ConvexHull(){}
private:
	std::vector<short> x;
	std::vector<short> y;
};

// defination

#endif


