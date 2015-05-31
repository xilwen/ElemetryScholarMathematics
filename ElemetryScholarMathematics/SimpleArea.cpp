#include "SimpleArea.h"

SimpleArea::SimpleArea(){}
SimpleArea::~SimpleArea(){}

void SimpleArea::ShowGraph()
{
	int RowNum = 0;
	cin >> RowNum;
	int i;

	int width;
	cin >> width;
	// width can control front white-space


	//For Picture 1
	int count = 1;

	//For Picture 2
	int count2 = 1;
	int judge = 1;

	//for 3
	int  ParallelogramLength;
	int JudgeTo3 = 1;
	cin >> ParallelogramLength;
	int length = width;

	//for 4
	int Row;
	int count4 = 1;
	int onecount = 0;
	int JudgeTo4 = 1;
	int JudgeTo5 = 1;

	cout << "The Mode You Choose:" << endl;

	for (i = 0; i < RowNum; i++)
	{
		//Picture1 Triangle


		SimpleArea::Print_WhiteSpace(0, width);// width can control front white-space

		int j = RowNum - i;

		SimpleArea::Print_WhiteSpace(0, j);
		SimpleArea::ShowTriangleLine(count);

		SimpleArea::Print_WhiteSpace(0, j);



		//  picture2 Rectangle
		SimpleArea::Print_WhiteSpace(0, width);

		// If it is the top or the end,print ******  else *    *
		if (judge == 1 || (i == RowNum - 1))
		{
			SimpleArea::Print_Star(0, width);       //I use width to be the length of Rectangle
			judge = 0;
		}
		else
		{
			cout << "*";
			SimpleArea::Print_WhiteSpace(1, width - 1);
			cout << "*";

		}

		//  picture3 Parallelogram

		SimpleArea::Print_WhiteSpace(0, width + 4); //+4 is for Typesetting

		SimpleArea::Print_WhiteSpace(0, length);
		cout << "*";
		// First print "      *"  then because JudgeTo3 =1 at first   print ***** or "     "  then add the final * then Padded the white -space

		if (i == RowNum - 1)
			JudgeTo3 = 1;
		if (JudgeTo3)
		{
			SimpleArea::Print_Star(0, ParallelogramLength - 1);
			JudgeTo3 = 0;

		}
		else
		{
			SimpleArea::Print_WhiteSpace(0, ParallelogramLength - 1);

		}

		cout << "*";
		SimpleArea::Print_WhiteSpace(0, i);



		//picture 4 Diamond

		SimpleArea::Print_WhiteSpace(0, width);

		if ((RowNum & 1) && JudgeTo4)
		{
			Row = (RowNum - 1) / 2;
			JudgeTo4 = 0;

		}
		else if ((!(RowNum & 1)) && JudgeTo4)
		{
			Row = RowNum / 2;
			JudgeTo4 = 0;
		}

		if (i < Row)
		{
			SimpleArea::Print_WhiteSpace(0, Row - i);
			SimpleArea::ShowTriangleLine(count4);
			cout << endl;
			count4 += 2;
		}
		else
		{
			if (!(RowNum & 1) && JudgeTo5)
			{
				onecount = 1;
				count4 -= 2;
				JudgeTo5 = 0;
			}

			SimpleArea::Print_WhiteSpace(0, onecount);

			SimpleArea::ShowTriangleLine(count4);

			cout << endl;
			count4 -= 2;
			onecount++;
		}
		length--;
		count += 2;
		count2 += 2;

	}


	int PrintNum = 1;
	while (PrintNum != 5)
	{
		cout << " ";
		SimpleArea::Print_WhiteSpace(0, 2 * width);
		cout << PrintNum << "  ";
		PrintNum++;
	}
	cout << endl;

}



void SimpleArea::ShowChristmasTree()
{

	int RowNum = 0;
	int i;
	int width; //from left to the graph

	int count = 1;
	int count2 = 9;

	cin >> RowNum;
	cin >> width;


	for (i = 0; i < RowNum; i++)
	{
		SimpleArea::Print_WhiteSpace(0, width+2);

		int j = RowNum - i;

		SimpleArea::Print_WhiteSpace(0, j);
		SimpleArea::ShowTriangleLine(count);

		SimpleArea::Print_WhiteSpace(0, j);

		cout << endl;
		count += 2;

	} //The first triangle of the Christmas Tree
	for (i = 0; i < RowNum-1; i++){


		SimpleArea::Print_WhiteSpace(0, width/2);
		int k = RowNum - i;
		SimpleArea::Print_WhiteSpace(0, k);
		SimpleArea::ShowTriangleLine(count2);

		SimpleArea::Print_WhiteSpace(0, k);


		cout << endl;
		count2 += 2;
	}
	//The second triangle of the Christmas Tree

	for (i = 0; i < RowNum-2 ; i++){
		SimpleArea::Print_WhiteSpace(0, width+6);
		int temp = 5;
		SimpleArea::ShowTriangleLine(temp);
		cout<<endl;
	}//The rectangleof the Christmas Tree
}


void SimpleArea::AreaCalculating()
{
	int mode;
	cout << "Choose your mode!" << endl;
	cin >> mode;
	if (mode == 1)
	{
		cout << "You Choose Triangle" << endl;
		double BottomEdge;
		double Height;
		cout << "Please Enter the BottomEdge  (m)" << endl;
		cin >> BottomEdge;
		cout << "Please Enter the Height  (m)" << endl;
		cin >> Height;
		double area = BottomEdge*Height / 2;

		cout << "The Area :  " << area << " (m^2)" << endl;


	}
	else if (mode == 2)
	{
		cout << "You Choose Rectangle" << endl;
		double Length;
		double Width;
		cout << "Please Enter the Length  (m)" << endl;
		cin >> Length;
		cout << "Please Enter the Width  (m)" << endl;
		cin >> Width;
		double area = Length*Width;

		cout << "The Area :  " << area << " (m^2)" << endl;


	}
	else if (mode == 3)
	{
		cout << "You Choose Parallelogram" << endl;
		double BottomEdge;
		double Height;
		cout << "Please Enter the BottomEdge  (m)" << endl;
		cin >> BottomEdge;
		cout << "Please Enter the Height  (m)" << endl;
		cin >> Height;
		double area = BottomEdge*Height;

		cout << "The Area :  " << area << " (m^2)" << endl;


	}
	else if (mode == 4)
	{

		cout << "You Choose Diamond" << endl;
		double LevelLength;
		double VerticalLength;
		cout << "Please Enter the LevelLength  (m)" << endl;
		cin >> LevelLength;
		cout << "Please Enter the VerticalLength  (m)" << endl;
		cin >> VerticalLength;
		double area = LevelLength*VerticalLength;

		cout << "The Area :  " << area << " (m^2)" << endl;



	}
	else
	{
		cout << "You enter the wrong mode!";
		exit(1);
	}
}


void SimpleArea::ShowTriangleLine(int& count)
{
	int Judge = 1;
	int temp = count;

	while (temp--)
	{
		if (Judge)
		{
			cout << "*";
			Judge = 0;
		}
		else
		{
			cout << " ";
			Judge = 1;

		}
	}
}


void SimpleArea::Print_WhiteSpace(int front, int back)
{
	for (int z = front; z < back; z++)
		cout << " ";

}
void SimpleArea::Print_Star(int front, int back)
{
	for (int z = front; z < back; z++)
		cout << "*";

}


