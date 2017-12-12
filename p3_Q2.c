#include <stdio.h>
#include <stdlib.h>
#define N 10
#define KANO0 3
#define KANO1 5
#define KANO2 4
#define KCUR0 1
#define KCUR1 4
#define KCUR2 2
#define KNUM0 6
#define KNUM1 8
#define KNUM2 4

float media_de_aleatorios(int ID) {
	int * p = (int *) malloc(N*sizeof(int));
	int i;
	float media = 0;
	for(i = 0; i < N; i++) {
		p[i] = rand()%9 + 1;
		media += (float)p[i];
	}
	free(p);
	return media;
}

int main() {
	int i = 0;
	int ID[3] = {(KANO0+KANO1+KANO2)%9 + 1,
	(KCUR0+KCUR1+KCUR2)%9 + 1,
	(KNUM0+KNUM1+KNUM2)%9 + 1};
	
	for (; i < 3; i++)
	{
		srand(ID[0]*100+ID[1]*10+ID[2]);
		printf("%do: %f\n", i +1, media_de_aleatorios(ID[i]));
	}
	
	return EXIT_SUCCESS;
}