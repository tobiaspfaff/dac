#include <iostream>
#include <wiringPi.h>
#include "mcp4725.hpp"
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
	unsigned char pic[100 * 100];
	FILE* fp = fopen("stingray.raw","rb");
	fread(&pic[0], 1, 100*100, fp);
	fclose(fp);

	vector<pair<double,double> > pos;
	for (int idx=0,y=0; y<100; y++) {
		for (int x=0; x<100; x++,idx++) {
			double str = (0xFF - pic[idx]) / 255.0;
			if (str > 0.82) {
				pos.push_back(pair<double,double> (0.01 * x, 0.01 * y));
			}
		}
	}
	random_shuffle(pos.begin(), pos.end());

	MCP4725 hs_mode(0x08);
	MCP4725 dac1(0x62);
	MCP4725 dac2(0x63);

	const int steps = 1000;
	int vbar = 0;
	for (int j=0; j<10000; j++) {

		/*for (int idx=0; idx<pos.size(); idx++) {
			auto& x = pos[idx];
			dac1.set(x.first);
			dac2.set(1.0 - x.second);
			delayMicroseconds(20);
		}*/

		/*for (int idx=0,y=0; y<100; y++) {
			bool rowset = false;
			for (int x=0; x<100; x++,idx++) {
				double str = (0xFF - pic[idx]) / 255.0;
				double xs = ((((double)rand()) / RAND_MAX) - 0.5);
				double ys = 0;//((((double)rand()) / RAND_MAX) - 0.5);
				if (str > 0.3) {
					if (!rowset) {
						rowset = true;
						dac2.set( 1.0 - (y+ys) * 0.01 );					
					}
					dac1.set( (xs+x) * 0.01 );
					//delayMicroseconds(10);
				}
			}
			if ((y % 10) == 0) {
				dac2.set( 1.0 - vbar * 0.01 );					
							
				for (int i=0; i<40; i++) {
					double x = (double)rand() / RAND_MAX;
					dac1.set( x );
				}
				delayMicroseconds(30);

			}
			vbar = (vbar + 1) % 100;
		}*/

		for (int y=0; y<100; y++) {
			dac2.set(1.0 - y * 0.01);
			for (int x=0; x<100; x++) {
				double v = (double)rand() / RAND_MAX;
				int idx0 = y*100 + (int)floor(v*99);
				int idx1 = y*100 + (int)ceil(v*99);
				if (pic[idx0] > 0xF0 && pic[idx1] > 0xF0) {
					dac1.set( v );				
				}
				delayMicroseconds(10);
			}
		}
		
		/*for (int i=0; i<steps; i++) {
			if ( (i % 10) < 5 ) {
				double alpha = ((double)rand()) / RAND_MAX;
				int x = (i+j) % steps;
				dac1.set( (double)x / steps) ;
				dac2.set(alpha);
			} else {
				double phi = (i+j) * 2.0 * 3.14 / steps;
				dac1.set(0.5 * sin(phi) + 0.5);
				dac2.set(0.5 * cos(phi) + 0.5);
			}
			//delay(1);


			delayMicroseconds(10);
		}*/
		/*for (int i=0; i<1000; i++) {
			double alpha = ((double)rand()) / RAND_MAX;
			dac1.set(i / 1000.0);
			dac2.set(alpha);
			delayMicroseconds(10);
		}*/
	}
	dac1.set(0);
	dac2.set(0);
	
	return 0;
}