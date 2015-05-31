#ifndef SIMPLEAREA_H
#define SIMPLEAREA_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class SimpleArea
{
public:
	SimpleArea();
	~SimpleArea();

	void ShowGraph();
	void AreaCalculating();
	void ShowTriangleLine(int& count);
	void Print_WhiteSpace(int front, int back);
	void Print_Star(int front, int back);

	void ShowChristmasTree();


private:
	double Area;
};

#endif