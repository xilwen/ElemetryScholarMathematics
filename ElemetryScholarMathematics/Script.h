#ifndef SCRIPT_H
#define SCRIPT_H
#include "ui.h"
#include "SimpleArea.h"
#include "BMPloader.h"
#include "ConvexHull.h" 
#include "PolygonArea.h"

class Script
{
public:
	Script();
	void runScripts();
	~Script();
private:
	UI* ui;
	SimpleArea SA;
	BMPloader* bmpl;

	PolygonArea* pa;
	std::vector<short> x;
	std::vector<short> y;
};

#endif
