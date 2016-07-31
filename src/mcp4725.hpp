#ifndef MCP4725_HPP
#define MCP4725_HPP

#include "i2c.hpp"

class MCP4725 : public I2C_Interface {
public:
	MCP4725(int address) : I2C_Interface(address) {}
	~MCP4725() {}

	void set(double value);
};

#endif