#include <iostream>
#include "Program.h"

int main() {

	Program p;
	p.ReportSwitches("switches.dat");
	p.ReportRouters("routers.dat");

	p.Update();
	
	return 0;
}
