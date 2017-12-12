#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define KANO0 3
#define KANO1 5
#define KANO2 4
#define KCUR0 1
#define KCUR1 4
#define KCUR2 2
#define KNUM0 6
#define KNUM1 8
#define KNUM2 4

double f(double x) { 
	double y = 0.0;
	double PI = 4.0*atan(1.0);
	int ID2 = (KNUM0+KNUM1+KNUM2)%9 + 1;
	switch(ID2) {
		case 0: y = x*x-5*x+6; break;
		case 1: y = 2.0*PI*x; break;
		case 2: y = PI*x*x; break;
		case 3: y = 6*x/PI; break;
		case 4: y = x*x*2.0*PI; break;
		case 5: y = -x*x+5*x-6; break;
		case 6: y = 3.5*x-2.0; break;
		case 7: y = PI*x/2.0; break;
		case 8: y = -PI*x+0.1*x; break;
		case 9: y = 2.0*x-3.0*PI; break;
		default: y = 0.0;
	}
	return y; 
}

int main() {
    int ID0 = (KANO0+KANO1+KANO2)%9 + 1,
        ID1 = (KCUR0+KCUR1+KCUR2)%9 + 1,
        ID2 = (KNUM0+KNUM1+KNUM2)%9 + 1;
	srand(ID0*100+ID1*10+ID2);
	double x, y; int i;
	FILE * arq;
	remove("dados.dat");
	arq = fopen("dados.dat","ab");
	for(i = 0; i < 100; i++) {
		x = (double) rand()/RAND_MAX;
		y = f(x);
		fwrite(&y,sizeof(double),1,arq);
	}
	printf("Codigo: %d%d%d\n",ID0,ID1,ID2);
	fclose(arq);
	return EXIT_SUCCESS;
}