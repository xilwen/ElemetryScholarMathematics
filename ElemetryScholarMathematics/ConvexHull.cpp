#include "ConvexHull.h"

ConvexHull::ConvexHull(const std::vector<short> a, const std::vector<short> b){}

//short ConvexHull::getx(short a){ return x[a]; }
//short ConvexHull::gety(short a){ return y[a]; }

// 找最左、最低的點
bool ConvexHull::compare(short a, short b)
{
	return (y[a] < y[b]) || (y[a] == y[a] && x[a] == x[b]);
}

// cross oa & ob, 大於零表示 oa 到 ob 為順時針旋轉
double ConvexHull::cross(short o, short a, short b)
{
	return (x[a] - x[o]) * (y[b] - y[o]) - (y[a] - y[o]) * (x[b] - x[o]);
}

std::vector<short> ConvexHull::findConvexHull(std::vector<short> a)
{
	/* 用 ConvexHull 上任一點當起點，這裡用最低、最左邊的點當起點 */

	int s = 0;
	for (unsigned int i = 0; i < a.size(); ++i)
		if (compare(a[i], a[s]))
			s = i;

	/* 以逆時針方向畫圖形*/

	std::vector<short> ch;
	ch[0] = a[s];			// 紀錄起點

	for (int m = 1; true; ++m)	// m 為 ConvexHull 的頂點個數
	{
		/* 窮舉所有的點，找出最外邊的一點 */

		int next = s;
		if (m == 1) next = !s;	/* 第一次 next 預設為起點以外的點
									否則 cross 會一直為零 */

		for (int i = 0; i<100; ++i)
			if (cross(ch[m], a[i], a[next]) < 0)
				next = i;

		if (next == s) break;	// 回到起點
		ch[m] = a[next];		// 紀錄剛剛找到的點
	}

	return ch;
}