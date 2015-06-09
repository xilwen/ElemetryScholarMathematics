#ifndef SCRIPT_H
#define SCRIPT_H
#include "ui.h"
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
