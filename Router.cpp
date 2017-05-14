#include "Router.h"

Router::Router() {
	SetNumOfPorts(2);
	for (int c = 0; c < GetNumOfPorts(); c++) {
		ConfigurePort(c, true);
		ConfigureProtocol(c, "N/A");
	}
}

Router::~Router() {

}

void Router::RunningConfig() {
	std::cout << "\n**Running Config Router**" << std::endl
		<< "ID-> " << int(this->GetID()) << std::endl
		<< "Vendor-> " << this->GetVendor() << std::endl
		<< "Model-> " << this->GetModel() << std::endl;

	for (int c = 0; c < this->GetNumOfPorts(); c++) {
		std::cout << "Port# " << c << " | Protocol-> " << GetProtocols()[c] << " |  Status-> ";
		if (GetUpDown()[c]) std::cout << "Up\n";
		else std::cout << "Down\n";
	}
	std::cout << std::endl;
}
