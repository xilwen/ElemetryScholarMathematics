#include "BMPloader.h"
#include "ConvexHull.h"


BMPloader::BMPloader(std::string fileLocation)
{
	std::fstream in;
	in.open(fileLocation);
	if (!in.is_open())
	{
#if _DEBUG
		std::cout << "No file readed!" << std::endl;
		getchar();
#endif
		exit(EXIT_FAILURE);// handler needed
	}
	in >> std::noskipws;
	unsigned char tmp;
	while (in >> tmp)
	{
		fileStorage.push_back(tmp);
	}
	file.close();
	findDots();
}

BMPloader::~BMPloader()
{
	
}

void BMPloader::findDots()
{
	char temp;
	unsigned int row = 0, column = 0;
	for (int i = 62; i < fileStorage.size(); i++)
	{
		temp = fileStorage[i];
		for (int j = 0; j < 8; j++)
		{
			row++;

			if (temp % 2 == 0)
			{
#if _DEBUG
				std::cout << "(" << row << "," << column << ") has a dot!" << std::endl;
#endif
				x.push_back(row);
				y.push_back(column);
			}
			temp = temp >> 1;
			if (row == 512)
			{
				column++;
				row = 0;
			}
		}
	}

}

void BMPloader::toConvexHull()
{
	ConvexHull convexhull(x, y);
}