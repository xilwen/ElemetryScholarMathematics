#ifndef SIMPLEAREA_H
#define SIMPLEAREA_H
void ShowTriangleLine(int &count);
void Print_WhiteSpace(int front, int back);
void Print_Star(int front, int back);
class SimpleArea
{
public:
	SimpleArea();
	~SimpleArea();

	void ShowGraph();
	void AreaCalculating();

private:
	double Area;
};

#endif