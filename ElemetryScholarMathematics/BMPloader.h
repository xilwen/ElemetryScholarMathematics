//written by xilwen

#ifndef BMPLOADER_H
#define BMPLOADER_H

#include <iostream>
#include <fstream>
#include <vector>

class BMPloader
{
public:
	//載入檔案名稱
	BMPloader();
	//(棄用)載入檔案名稱
	//BMPloader(std::string);
	//(棄用)將檔案載入儲存空間
	int init();
	//將檔案載入儲存空間，回傳0為正常返回、1=開檔失敗、2=格式不符、3=圖片全白、4=檔案破損
	int init(std::string);

	//getters
	std::vector<short> getX(){ return x; }
	std::vector<short> getY(){ return y; }

	
	~BMPloader();



private:
	void findDots();
	std::string fileLocation;
	std::vector<char> fileStorage;
	std::vector<short> x;
	std::vector<short> y;

};

#endif