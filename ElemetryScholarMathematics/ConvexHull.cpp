#include "ConvexHull.h"

ConvexHull::ConvexHull(){}
ConvexHull::ConvexHull(vector<short> x1, vector<short> y1) : x0(x1), y0(y1){}


void ConvexHull::sort()
{
	int i, j;
	int count = x0.size();

	for (i = 0; i < count; i++)
	{
 
		for (j = i + 1 ; j < count ; j++)
		{	
			if (ConvexHull::compare(i, j))
			{
				ConvexHull::swap(i, j);
			}
		}
	}

}

void ConvexHull::swap(int i, int j)
{

	short temp;
	temp = x0[i];
	x0[i] = x0[j];
	x0[j] = temp;

	temp = y0[i];
	y0[i] = y0[j];
	y0[j] = temp;

}

double ConvexHull::cross(int o, int a, int b)
{
	return (x[a] - x[o]) * (y0[b] - y[o]) - (y[a] - y[o]) * (x0[b] - x[o]);
}


bool ConvexHull::compare(int a, int b)
{
	return (x0[a] < x0[b]) || ((x0[a] == x0[b] )&& (y0[a] < y0[b]));
}

void  ConvexHull::Andrew_monotone_chain()
{
	ConvexHull::sort();
	int  m = 0;
	int count = x0.size();
	for (int i = 0; i<count; ++i)
	{
		while (m >= 2 && cross(m - 2,m - 1,i) <= 0)   m--;

		x.push_back(x0[i]);
		y.push_back(y0[i]);
		m++;
	}
	for (int i = count - 2, t = m + 1; i >= 0; --i)
	{
	
		while (m >= t && cross( m - 2, m - 1, i) <= 0)   m--;
		x.push_back(x0[i]);
		y.push_back(y0[i]);
		m++;
	}

	m--;
}