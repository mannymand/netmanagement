#include "Device.h"

Device::Device():ID(24), Vendor("N/A"), Model("N/A"){

}

Device::~Device(){

}

Device::Device(std::string _v, std::string _m, short int _p) : Vendor(_v), Model(_m), NumOfPorts(_p) {

}

void Device::RunningConfig() {
	std::cout << "\n****Running Config****" << std::endl
		<< "ID-> " << int(this->GetID()) << std::endl 
		<< "Vendor-> " << this->GetVendor() << std::endl 
		<< "Model-> " << this->GetModel() << std::endl;

	for (int c = 0; c < this->GetNumOfPorts(); c++) {
		std::cout << "Port# " << c << " | Protocol-> " << Protocol[c] << " |  Status-> ";
		if (UpDown[c]) std::cout << "Up\n";
		else std::cout << "Down\n";

	}
}

void Device::ConfigurePort(int _p, bool _s) {
	if (_p < this->NumOfPorts) 
	{
		this->UpDown[_p] = _s;
	}
}

void Device::ConfigureProtocol(int _p, std::string _pr) {
	if (_p < this->NumOfPorts)
		this->Protocol[_p] = _pr;
}
