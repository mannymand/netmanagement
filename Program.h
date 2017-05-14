#pragma once
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "Switch.h"
#include "Router.h"
#include "StringException.h"

class Program
{
public:
	Program();
	~Program();
	
	void ReportSwitches(std::string _filep);
	void ReportRouters(std::string _filep);

	void Run();

	void Update();
	void UpdateSwitches();
	void UpdateRouters();

	void UpdateSwitch();
	void UpdateRouter();
private:
	int Data;
	int device;
	std::vector<Switch> switches;
	std::vector<Router> routers;
};
