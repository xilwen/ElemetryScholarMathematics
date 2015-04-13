#include "ConvexHull.h"

ConvexHull::ConvexHull(const std::vector<short> a, const std::vector<short> b){}

//short ConvexHull::getx(short a){ return x[a]; }
//short ConvexHull::gety(short a){ return y[a]; }

// ��̥��B�̧C���I
bool ConvexHull::compare(short a, short b)
{
	return (y[a] < y[b]) || (y[a] == y[a] && x[a] == x[b]);
}

// cross oa & ob, �j��s��� oa �� ob �����ɰw����
double ConvexHull::cross(short o, short a, short b)
{
	return (x[a] - x[o]) * (y[b] - y[o]) - (y[a] - y[o]) * (x[b] - x[o]);
}

std::vector<short> ConvexHull::findConvexHull(std::vector<short> a)
{
	/* �� ConvexHull �W���@�I��_�I�A�o�̥γ̧C�B�̥��䪺�I��_�I */

	int s = 0;
	for (unsigned int i = 0; i < a.size(); ++i)
		if (compare(a[i], a[s]))
			s = i;

	/* �H�f�ɰw��V�e�ϧ�*/

	std::vector<short> ch;
	ch[0] = a[s];			// �����_�I

	for (int m = 1; true; ++m)	// m �� ConvexHull �����I�Ӽ�
	{
		/* �a�|�Ҧ����I�A��X�̥~�䪺�@�I */

		int next = s;
		if (m == 1) next = !s;	/* �Ĥ@�� next �w�]���_�I�H�~���I
									�_�h cross �|�@�����s */

		for (int i = 0; i<100; ++i)
			if (cross(ch[m], a[i], a[next]) < 0)
				next = i;

		if (next == s) break;	// �^��_�I
		ch[m] = a[next];		// ��������쪺�I
	}

	return ch;
}