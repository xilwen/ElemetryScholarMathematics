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
};

#endif
