#include <iostream>
#include <wiringPi.h>
#include "mcp4725.hpp"

using namespace std;

int main() {
	MCP4725 dac(0x62);

	dac.set(0);
	delay(2000);
	dac.set(1);
	delay(2000);
	dac.set(0.5);
	
	return 0;
}