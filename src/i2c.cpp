#include "i2c.hpp"
#include "utils.hpp"

#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

I2C_Interface::I2C_Interface(int address) : 
	address(address) 
{
	fd = open("/dev/i2c-1", O_RDWR);
	if (fd < 0)
		ERROR("Can't open I2C device");
	if (ioctl(fd, I2C_SLAVE, address))
		ERROR("Can't set I2C device to slave mode");
}

I2C_Interface::~I2C_Interface() {
	close(fd);
}

void I2C_Interface::write_two_bytes(int d0, int d1) {
	i2c_smbus_ioctl_data args;
	i2c_smbus_data data;

	args.read_write = I2C_SMBUS_WRITE;
	args.command = d0 & 0xff;
	args.size = I2C_SMBUS_BYTE_DATA;
	args.data = &data;
	data.byte = d1 & 0xff;	

	if (ioctl(fd, I2C_SMBUS, &args))
		ERROR("Can't write to device");
}
