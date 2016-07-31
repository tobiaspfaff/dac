#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

int main() {
	int fd = open("/dev/i2c-1", O_RDWR);
	cout << fd << endl;	
	int res = ioctl(fd, I2C_SLAVE, 0x62);
	cout << res << endl;	
	
	i2c_smbus_ioctl_data args;
	i2c_smbus_data data;
	args.read_write = I2C_SMBUS_WRITE;
	args.command = 0x0f;
	args.size = I2C_SMBUS_BYTE_DATA;
	args.data = &data;
	data.byte= 0xff;
	
	res = ioctl(fd, I2C_SMBUS, &args);
	cout << res << endl;	

	return 0;
}