#pragma once
#include "Device.h"
class Switch : public Device {
public:
	Switch();
	~Switch();

	Switch(bool _svi, unsigned char _p);
	void RunningConfig();

private:
	bool SVI;
};
