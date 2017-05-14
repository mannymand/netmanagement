#include "Switch.h"

Switch::Switch(): SVI(false) {
	SetNumOfPorts(4);
	for (int c = 0; c < GetNumOfPorts(); c++) {
		ConfigurePort(c, true);
		ConfigureProtocol(c, "N/A");
	}
		
}


Switch::~Switch() {

}

Switch::Switch(bool _svi, unsigned char _p): SVI(_svi) {
	SetNumOfPorts(_p);
	for (int c = 0; c < GetNumOfPorts(); c++) {
		ConfigurePort(c, false);
		ConfigureProtocol(c, "N/A");
	}
}

void Switch::RunningConfig() {
	std::cout << "\n***Running Config Switch***" << std::endl
		<< "ID-> " << int(this->GetID()) << std::endl
		<< "Vendor-> " << this->GetVendor() << std::endl
		<< "Model-> " << this->GetModel() << std::endl;

	for (int c = 0; c < this->GetNumOfPorts(); c++) {
		std::cout << "Port# " << c << " | Protocol-> " << GetProtocols()[c] << " |  Status-> ";

		if (GetUpDown()[c]) std::cout << "Up\n";
		else std::cout << "Down\n";

	}
	if (this->SVI) std::cout << "\nSVI-> ENABLED\n";
	else std::cout << "\nSVI-> DISABLED\n";
	
	std::cout << std::endl;
}

