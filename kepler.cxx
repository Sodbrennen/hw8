#include <iostream>
#include <math.h>

#define PI (3.141592653589793)


using namespace std;

void symplStep(double* qn, double* pn, double e, double dt){
	

		pn[0] -= dt*(qn[0]/pow((qn[0]*qn[0] + qn[1]*qn[1]),1.5));
		pn[1] -= dt*(qn[1]/pow((qn[0]*qn[0] + qn[1]*qn[1]),1.5));
		qn[0] += dt*pn[0];
		qn[1] += dt*pn[1];

}


int main(){

	double pn[2];
	double qn[2];
	double H;

	double e = 0.6;
	double dt = 0.05; 
	double T = 20*PI;

	// initial values

	qn[0] = 1 - e;
	qn[2] = 0;
	pn[0] = 0;
	pn[1] = sqrt((1 + e)/(1 - e));

	// DO

	for(int j = 0; j*dt <= T; j++){
		
		H = 0.5*(pn[0]*pn[0] + pn[1]*pn[1]) - 1/sqrt(qn[0]*qn[0] + qn[1]*qn[1]);

		cout << qn[0] << "\t" <<  qn[1] << "\t" << j*dt << "\t" <<  H << endl;
		symplStep(qn,pn,e,dt);

	}

}

		
