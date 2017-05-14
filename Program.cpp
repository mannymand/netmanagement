#include "Program.h"
Program::Program(): Data(0), device(-1) {
	for (int c = 0; c < 10; c++) {
		Switch sw;
		sw.SetID(c);
		switches.push_back(sw);
	}
	for (int c = 0; c < 5; c++) {
		Router r;
		r.SetID(c);
		routers.push_back(r);
	}
}


Program::~Program() {

}

void Program::ReportSwitches(std::string _filep) {
	std::ofstream file(_filep);
	if (file.is_open())
	{
		file << " Switch ID		Vendor		Model \n";
		for (int c = 0; c < switches.size(); c++) {
			file << "\t" << switches[c].GetID() << "\t\t\t" << switches[c].GetVendor() << "\t\t\t" << switches[c].GetModel() << "\t\t\t";
		
			for (int i = 0; i < switches[c].GetNumOfPorts(); i++) {
				if (switches[c].GetUpDown()[i]) file << "faEth0/" << i << " UP/" << switches[c].GetProtocols()[i] << "\t";
				else file << "faEth0/" << i << " Down\t";
			}
			file << "\n";
		}
		file.close();
	}
}

void Program::ReportRouters(std::string _filep) {
	std::ofstream file(_filep);
	if (file.is_open())
	{
		file << " Router ID		Vendor		Model \n";
		for (int c = 0; c < routers.size(); c++) {
			file << "\t" << routers[c].GetID() << "\t\t\t" << routers[c].GetVendor() << "\t\t\t" << routers[c].GetModel() << "\t\t\t";
			for (int i = 0; i < routers[c].GetNumOfPorts(); i++) {
				if (routers[c].GetUpDown()[i]) file << "se0/" << i << " UP/" << routers[c].GetProtocols()[i] << "\t";
				else file << "faEth0/" << i << " Down\t";
			}
			file << "\n";
		}
		file.close();
	}
}


void Program::Run() {
	
}

void Program::Update() {
	int key = -1;

	while (key !=6) {
		std::cout << "****Options****\n";
		std::cout << "[1] Print All\n";
		std::cout << "[2] Config Switch\n";
		std::cout << "[3] Config Router\n";
		std::cout << "[4] Update Switch Table\n";
		std::cout << "[5] Update Router Table\n";
		std::cout << "[6] Exit!\n";

		std::cout << "Enter option ";
		std::cin >> key;
		system("CLS");
		std::cout << "****Options****\n";
		std::cout << "[1] Print All\n";
		std::cout << "[2] Config Switch\n";
		std::cout << "[3] Config Router\n";
		std::cout << "[4] Update Switch Table\n";
		std::cout << "[5] Update Router Table\n";
		std::cout << "[6] Exit!\n";

		if (key == 1) {
			for (int c = 0; c < switches.size(); c++)
				switches[c].RunningConfig();
			for (int c = 0; c < routers.size(); c++)
				routers[c].RunningConfig();
		}
		else if (key == 2) {
			// clears the screen
			system("CLS");
			UpdateSwitches();
		}

		else if (key == 3) {
			system("CLS");
			UpdateRouters();
		}
		else if (key == 4)
			ReportSwitches("switches.dat");
		else if (key == 5)
			ReportRouters("routers.dat");
	}
		
}

void Program::UpdateSwitches() {
	int key = -1;
	while (key != 3) {
		std::cout << "****Switch Options****\n";
		std::cout << "[1] Print All\n";
		std::cout << "[2] Select Device\n";
		std::cout << "[3] Exit!\n";

		std::cout << "Enter option ";
		std::cin >> key;
		system("CLS");
		std::cout << "****Switch Options****\n";
		std::cout << "[1] Print All\n";
		std::cout << "[2] Select Device\n";
		std::cout << "[3] Exit!\n";

		if (key == 1) {
			for (int c = 0; c < switches.size(); c++)
				switches[c].RunningConfig();
		}

		else if (key == 2) {
			std::cout << "Enter Device ID\n";
			std::cin >> device;
			system("CLS");
			UpdateSwitch();
		}
	}

	system("CLS");

}

void Program::UpdateRouters() {
	int key = -1;
	while (key != 3) {
		std::cout << "****Router Options****\n";
		std::cout << "[1] Print All\n";
		std::cout << "[2] Select Device\n";
		std::cout << "[3] Exit!\n";
		
		std::cout << "Enter option ";
		std::cin >> key;
		system("CLS");

		std::cout << "**** RouterOptions****\n";
		std::cout << "[1] Print All\n";
		std::cout << "[2] Select Device\n";
		std::cout << "[3] Exit!\n";

		if (key == 1)
			for (int c = 0; c < routers.size(); c++)
				routers[c].RunningConfig();

		else if (key == 2) {
			std::cout << "Enter Device ID ";
			std::cin >> device;
			system("CLS");
			UpdateRouter();

		}
	}
	system("CLS");
}

void Program::UpdateSwitch() {
	int key = -1;
	std::string s;
	int p;
	std::cout << "****Switch ID: " << device << " Options****\n";
	std::cout << "[1] Print \n";
	std::cout << "[2] Configure Port\n";
	std::cout << "[3] Configure Protocol\n";
	std::cout << "[4] Configure Vendor\n";
	std::cout << "[5] Configure Model\n";
	std::cout << "[6] Kill All\n";
	std::cout << "[7] Delete Record\n";
	std::cout << "[8] Exit!\n";
	while (key != 8) {

		std::cout << "Enter option ";
		std::cin >> key;
		system("CLS");

		std::cout << "****Switch Options****\n";
		std::cout << "[1] Print \n";
		std::cout << "[2] Configure Port\n";
		std::cout << "[3] Configure Protocol\n";
		std::cout << "[4] Configure Vendor\n";
		std::cout << "[5] Configure Model\n";
		std::cout << "[7] Delete Record\n";
		std::cout << "[8] Exit!\n";

		if (key == 1)
			switches[device].RunningConfig();

		else if (key == 2) {
			std::cout << "Enter #Port and State ( 1 Up, 0 Down) \n";
			bool s;
			std::cin >> p;
			std::cin >> s;
			switches[device].ConfigurePort(p, s);
			system("CLS");
		}
		else if (key == 3) {
			std::cout << "Enter #Port and Protocol \n";
			std::cin >> p;
			std::cin >> s;
			switches[device].ConfigureProtocol(p, s);
			system("CLS");
		}
		else if (key == 4) {
			std::cout << "Enter device vendor \n";
			std::cin >> s;
			switches[device].SetVendor(s);
			system("CLS");
		}
		else if (key == 5) {
			std::cout << "Enter device model \n";
			std::cin >> s;
			switches[device].SetModel(s);
			system("CLS");
		}
		else if (key == 6) {
			for (int c = 0; c < switches[device].GetNumOfPorts(); c++)
				switches[device].KillAll();
		}
		else if (key == 7) {
			switches.erase(switches.begin() + device);
			key = 8;
		}
	}
	device = -1;
	system("CLS");
}

void Program::UpdateRouter() {
	int key = -1;
	std::string s;
	int p;
	std::cout << "****Router ID: " << device << " Options****\n";
	std::cout << "[1] Print \n";
	std::cout << "[2] Configure Port\n";
	std::cout << "[3] Configure Protocol\n";
	std::cout << "[4] Configure Vendor\n";
	std::cout << "[5] Configure Model\n";
	std::cout << "[7] Delete Record\n";
	std::cout << "[8] Exit!\n";
  
	while (key != 8) {
		std::cout << "Enter option ";
		std::cin >> key;
		system("CLS");
		std::cout << "****Router Options****\n";
		std::cout << "[1] Print \n";
		std::cout << "[2] Configure Port\n";
		std::cout << "[3] Configure Protocol\n";
		std::cout << "[4] Configure Vendor\n";
		std::cout << "[5] Configure Model\n";
		std::cout << "[7] Delete Record\n";
		std::cout << "[8] Exit!\n";
    
		if (key == 1)
			routers[device].RunningConfig();

		else if (key == 2) {
			std::cout << "Enter #Port and State ( 1 Up, 0 Down) \n";

			bool s;

			std::cin >> p;
			std::cin >> s;
			routers[device].ConfigurePort(p, s);
			system("CLS");
		}
		else if (key == 3) {
			std::cout << "Enter #Port and Protocol \n";
			std::cin >> p;
			std::cin >> s;
			routers[device].ConfigureProtocol(p, s);
			system("CLS");
		}
		else if (key == 4) {
			std::cout << "Enter device vendor \n";
			std::cin >> s;
			routers[device].SetVendor(s);
			system("CLS");
		}
		else if (key == 5) {
			std::cout << "Enter device model \n";
			std::cin >> s;
			routers[device].SetModel(s);
			system("CLS");
		}
		else if (key == 6) {
			for (int c = 0; c < routers[device].GetNumOfPorts(); c++)
				routers[device].KillAll();
		}
		else if (key == 7) {
			// erase is a c++ function, erases it from the list
			routers.erase(routers.begin() + device);
			key = 8;
		}
	}
	device = -1;
	system("CLS");
}
