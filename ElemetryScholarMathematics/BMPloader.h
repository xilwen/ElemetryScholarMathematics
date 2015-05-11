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
	void findDots();
	void toConvexHull();

	//關檔案
	~BMPloader();
private:
	std::fstream file;
	std::vector<char> fileStorage;
	std::vector<short> x;
	std::vector<short> y;
};

#endif