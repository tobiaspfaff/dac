#include "utils.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

void ERROR(const char* msg) {
	cout << "FATAL ERROR: " << msg << endl;
	exit(1);
}

void WARNING(const char* msg) {
	cout << "WARNING: " << msg << endl;
}