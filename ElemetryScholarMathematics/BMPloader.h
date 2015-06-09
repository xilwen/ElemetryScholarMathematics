//written by xilwen

#ifndef BMPLOADER_H
#define BMPLOADER_H

#include <iostream>
#include <fstream>
#include <vector>

class BMPloader
{
public:
	BMPloader() = delete;
	//開檔案
	BMPloader(std::string);
	
	void toConvexHull();

	std::vector<short> getX(){ return x; }
	std::vector<short> getY(){ return y; }

	//關檔案
	~BMPloader();



private:
	void findDots();
	//std::fstream file;
	std::vector<char> fileStorage;
	std::vector<short> x;
	std::vector<short> y;

};

#endif