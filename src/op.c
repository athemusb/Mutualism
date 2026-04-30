#include <stdio.h>
#include "../rps.h"

void op(int k, double *v, double *p){
	int x;
	FILE *file, *arq;
	char name[100], nome[100];

	sprintf(name, "dat/v/%d.dat", k);
	sprintf(nome, "dat/p/%d.dat", k);
	file= fopen(name, "w");
	arq=  fopen(nome, "w");
	for(x= 0; x< Nx; x++){
		fprintf(file, "%d %e ", x, v[x]);
		fprintf(arq,  "%d %e ", x, p[x]);
		fprintf(file, "\n");
		fprintf(arq,  "\n");
	}

	fclose(file);
	fclose(arq);
}
