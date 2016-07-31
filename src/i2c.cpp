#include "i2c.hpp"

I2C_Interface::I2C_Interface(int address) : 
	address(address) 
{
	fd = open("/dev/i2c-1", O_RDWR);
	
}
