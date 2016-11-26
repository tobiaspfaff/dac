#ifndef UTILS_HPP
#define UTILS_HPP

void ERROR(const char* msg);
void WARNING(const char* msg);

inline double clamp(double x, double xmin, double xmax) {
	return (x < xmin) ? xmin : ( (x>xmax) ? xmax : x );
}

#endif