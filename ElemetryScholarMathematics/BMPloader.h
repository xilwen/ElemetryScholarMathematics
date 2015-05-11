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
	//�}�ɮ�
	BMPloader(std::string);
	void findDots();
	void toConvexHull();

	//���ɮ�
	~BMPloader();
private:
	std::fstream file;
	std::vector<char> fileStorage;
	std::vector<short> x;
	std::vector<short> y;
};

#endif