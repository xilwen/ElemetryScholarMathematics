#include "SimpleArea.h"

SimpleArea::SimpleArea(){}
SimpleArea::~SimpleArea(){}

void SimpleArea::ShowGraph()
{
	int RowNum = 5;
	//cin >> RowNum;
	int i;

	int width = 5;
	//cin >> width;
	// width can control front white-space


	//For Picture 1
	int count = 1;

	//For Picture 2
	int count2 = 1;
	int judge = 1;

	//for 3
	int  ParallelogramLength = 5;
	int JudgeTo3 = 1;
	//cin >> ParallelogramLength;
	int length = width;

	//for 4
	int Row;
	int count4 = 1;
	int onecount = 0;
	int JudgeTo4 = 1;
	int JudgeTo5 = 1;

	cout << "選擇一種圖案" << endl;

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
		SimpleArea::Print_WhiteSpace(0, width + 2);

		int j = RowNum - i;

		SimpleArea::Print_WhiteSpace(0, j);
		SimpleArea::ShowTriangleLine(count);

		SimpleArea::Print_WhiteSpace(0, j);

		cout << endl;
		count += 2;

	} //The first triangle of the Christmas Tree
	for (i = 0; i < RowNum - 1; i++){


		SimpleArea::Print_WhiteSpace(0, width / 2);
		int k = RowNum - i;
		SimpleArea::Print_WhiteSpace(0, k);
		SimpleArea::ShowTriangleLine(count2);

		SimpleArea::Print_WhiteSpace(0, k);


		cout << endl;
		count2 += 2;
	}
	//The second triangle of the Christmas Tree

	for (i = 0; i < RowNum - 2; i++){
		SimpleArea::Print_WhiteSpace(0, width + 6);
		int temp = 5;
		SimpleArea::ShowTriangleLine(temp);
		cout << endl;
	}//The rectangleof the Christmas Tree
}


void SimpleArea::AreaCalculating()
{
	int mode;
	cout << "選擇你要的圖案!" << endl;
	cin >> mode;
	cout << endl;
	if (mode == 1)
	{
		cout << "選擇三角形" << endl;
		double BottomEdge;
		double Height;

		cout << endl << "請輸入底邊  (m)" << endl << endl;
		cin >> BottomEdge;
		cout << endl << "請輸入高  (m)" << endl << endl;
		cin >> Height;
		double area = BottomEdge*Height / 2;

		cout << endl << "面積 :  " << area << " (m^2)" << endl << endl;


	}
	else if (mode == 2)
	{
		cout << "選擇矩形" << endl << endl;
		double Length;
		double Width;
		cout << endl << "請輸入長  (m)" << endl << endl;
		cin >> Length;
		cout << endl << "請輸入寬  (m)" << endl << endl;
		cin >> Width;
		double area = Length*Width;

		cout << endl << "面積 :  " << area << " (m^2)" << endl << endl;


	}
	else if (mode == 3)
	{
		cout << "選擇平行四邊形" << endl << endl;
		double BottomEdge;
		double Height;
		cout << endl << "請輸入底邊  (m)" << endl << endl;
		cin >> BottomEdge;
		cout << endl << "請輸入高  (m)" << endl << endl;
		cin >> Height;
		double area = BottomEdge*Height;

		cout << endl << "面積 :  " << area << " (m^2)" << endl << endl;


	}
	else if (mode == 4)
	{

		cout << "選擇菱形" << endl << endl;
		double LevelLength;
		double VerticalLength;
		cout << endl << "請輸入水平長度  (m)" << endl << endl;
		cin >> LevelLength;
		cout << endl << "請輸入垂直長度  (m)" << endl << endl;
		cin >> VerticalLength;
		double area = LevelLength*VerticalLength;

		cout << endl << "面積 :  " << area << " (m^2)" << endl << endl;



	}
	else
	{
		cout << "輸入錯摟!";
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


void SimpleArea::Show_Triangle(int Bottom, int Height)
{
	
	int i;
	int whitespace = Height;
	int addition = (Bottom - 1) / Height+1;
	SimpleArea::Print_WhiteSpace(0,whitespace);
	cout << "*" << endl;
	int count = 2;


	for (i = 0; i < Height-1; i++)
	{
		whitespace -= 1;
		SimpleArea::Print_WhiteSpace(0, whitespace);
		if (i == Height - 2)
		{
			SimpleArea::Print_Star(0, Bottom);
			break;
		}
		else if ((Height-Bottom)>=3 && i == Height/2)
		{
			addition++;
		
		}
		// These are to make the shape irregular
		SimpleArea::Print_Star(0, count);

		cout << endl;
		count += addition;
		
	}

	cout << endl;
}

void SimpleArea::Show_Rectangle(int Bottom, int Height)
{
	int i;
	int judge = 1;
	for (i = 0; i < Height; i++)
	{

		if (judge == 1 || (i == Height - 1))
		{
			SimpleArea::Print_Star(0, Bottom);       //I use width to be the length of Rectangle
			judge = 0;
		}
		else
		{
			cout << "*";
			SimpleArea::Print_WhiteSpace(1, Bottom - 1);
			cout << "*";

		}
		cout << endl;
	}


}
void SimpleArea::Show_Parallelogram(int Bottom, int Height)
{
	int i,Judge=1;
	int length = Height;
	for (i = 0; i < Height; i++)
	{
		SimpleArea::Print_WhiteSpace(0, length);
		cout << "*";
		// First print "      *"  then because JudgeTo3 =1 at first   print ***** or "     "  then add the final * then Padded the white -space

		if (i == Height - 1)
			Judge = 1;
		if (Judge)
		{
			SimpleArea::Print_Star(0, Bottom - 1);
			Judge = 0;

		}
		else
		{
			SimpleArea::Print_WhiteSpace(0, Bottom - 1);

		}

		cout << "*";
		SimpleArea::Print_WhiteSpace(0, i);
		cout << endl;

		length--;
	}


}
void SimpleArea::Show_Diamond(int Height){
	//Height is to control the up part of the diamond

	int i, j;
	for (i = 1; i <= Height; i++)
	{
		for (j = Height; j >= i; j--)
			cout << " ";
		SimpleArea::Print_Star(1, 2 * i );
			cout << endl;

	}

	for (i = Height - 1; i >= 1; i--)
	{
		for (j = Height; j >= i; j--)
			cout << " ";
		SimpleArea::Print_Star(1, 2 * i);
		cout << endl;
	}



}