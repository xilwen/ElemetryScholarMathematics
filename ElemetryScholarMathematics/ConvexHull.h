//written by qqwerfdsa930 and GODKING

#pragma once
#include <vector>
#include <iostream>
#include <string>
class ConvexHull
{
public:
	ConvexHull();
	ConvexHull(std::vector<short>, std::vector<short>); // (x , y)

	int toUI(int line, std::string[]); //(How many lines to print, texts to print) for DEBUG

	~ConvexHull();
private:
	int x;
	int y;
};