#include "BMPloader.h"
#include "ConvexHull.h"

BMPloader::BMPloader()
{
}


int BMPloader::init()
{
	try{
		std::fstream in;
		in.open(fileLocation);
		if (!in.is_open())
			throw 1;
		in >> std::noskipws;
		unsigned char tmp;
		while (in >> tmp)
		{
			fileStorage.push_back(tmp);
		}
		in.close();

		if (fileStorage.size() < 29)
			throw 4;
		if (fileStorage[18] != 0 || fileStorage[19] != 2 || fileStorage[20] != 0 || fileStorage[21] != 0 ||
			fileStorage[22] != 0 || fileStorage[23] != 2 || fileStorage[24] != 0 || fileStorage[25] != 0 ||
			fileStorage[0] != 'B' || fileStorage[1] != 'M' ||
			fileStorage[28] != 1 || fileStorage[29] != 0)
			throw 2;
		findDots();
		if (x.size() == 0 || y.size() == 0)
			throw 3;
		return 0;
	}
	catch (int e)
	{
		return e;
	}
	catch (...)
	{
		return 999;
	}
}

int BMPloader::init(std::string _fileLocation)
{
	fileLocation = _fileLocation;
	return init();
}


BMPloader::~BMPloader()
{
}

void BMPloader::findDots()
{
	unsigned char temp;
	unsigned int row = 0, column = 0;
	unsigned char stackalign = 0;
	for (unsigned int i = 62; i < fileStorage.size(); i++)
	{
		temp = fileStorage[i];
		for (int j = 0; j < 8; j++)
		{
			
			if (temp % 2 == 0)
			{
				x.push_back(row + (7 - stackalign));
				y.push_back(column);
			}
			;
			temp = temp >> 1;
			++stackalign;
			if (stackalign > 7)
			{
				stackalign = 0;
				row += 8;
			}
			if (row == 512)
			{				
				++column;
				row = 0;
			}
		}
	}	
}
