#ifndef I2C_HPP
#define I2C_HPP

class I2C_Interface {
public:
	I2C_Interface(int address);
	~I2C_Interface();

protected:
	void write_two_bytes(int d0, int d1);

	int address;
	int fd;
};

#endif