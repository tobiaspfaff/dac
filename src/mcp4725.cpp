#include "mcp4725.hpp"
#include "utils.hpp"

void MCP4725::set(double val) {
	// [0,1] -> 12bit
	int data = (int) clamp(val * 4095, 0, 4095);

	// fast mode protocol
	write_two_bytes( (data >> 8) & 0x0F, data & 0xFF);	
}