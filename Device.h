#pragma once

#include <iostream>
#include <string>

class Device {
public:
	Device();
	~Device();
	Device(std::string _v, std::string _m, short int _p);

	inline void SetVendor(std::string _v) 
	{ 
		this->Vendor = _v; 
	}
	inline void SetModel(std::string _m) { this->Model = _m; }
	inline void SetNumOfPorts(unsigned char _p) { this->NumOfPorts = _p; }
	inline void SetID(short int _id) { this->ID = _id; }

	inline short int GetID() { return this->ID; }
	inline std::string GetVendor() { return this->Vendor; }
	inline std::string GetModel() { return this->Model; }
	inline unsigned char GetNumOfPorts() { return this->NumOfPorts; }
	inline std::string *GetProtocols() { return this->Protocol; }
	inline bool* GetUpDown() { return this->UpDown; }
	
	void RunningConfig();

	void ConfigurePort(int _p, bool _s);
	void ConfigureProtocol(int _p, std::string _pr);
	
	inline void KillAll() { for (int c = 0; c < NumOfPorts; c++) UpDown[c] = false; }
private:
	short int ID;
	std::string Vendor;
	std::string Model;

	short int NumOfPorts;
	std::string Protocol[24];
	bool UpDown[24];
};
