#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gsl/gsl_rng.h>
#include "../rps.h"


void op(int, double *, double *);
void abund(double *v, double *p);

int main(int argc, char **argv){
	int i, x, k=0, L;
	int xp1, xm1, B;
	double t, I, P_e, dist, a0=q, L_v, L_p;
	double *v, *p;


	if (argc != 1) {
		printf("Please insert %s\n", argv[0]);
		exit(1);
	}

//Vector memory allocation (wraped matrix)
	v= (double *) calloc(Nx, sizeof(double)); //vegetation field
	p= (double *) calloc(Nx, sizeof(double));

//random function initialization
	gsl_rng_default_seed= (argc == 3) ? atoi(argv[1]) : time(NULL) ;
	gsl_rng *w= gsl_rng_alloc(gsl_rng_mt19937);

//Initial Condidion
	for(x= 0; x< Nx; x++){
		v[x]= 0.40 + gsl_rng_uniform(w)/100;
		p[x]= 1.90 + gsl_rng_uniform(w)/100;
	}
	gsl_rng_free(w);
	op(0, v, p);

//Time Loop
	t= 0.0; L= R/(dx);
	while (t< tf) {
		for(x= 0; x< Nx; x++){
			I= 0.0;
			xp1= (x+1)%Nx;
			xm1= (x-1+Nx)%Nx;
			B=0;
			for(i= 0; i<= 2*L; i++){
				dist= (i-L)*(i-L);
				if(dist <= L*L){
					I+= 0.5*v[(x+i-L+Nx)%Nx]*dx;
					B++;
				}
			}
			P_e= 1/(1+a*I);
			L_v= (v[xp1] + v[xm1] - 2.0*v[x])/(dx*dx);
			L_p= (p[xp1] + p[xm1] - 2.0*p[x])/(dx*dx);
			v[x]= v[x] + dt*(P_e*v[x]*p[x]*(1-v[x]) - v[x] + D_v*L_v);
			p[x]= p[x] + dt*(b*p[x] - g*p[x]*p[x] + m*v[x]*p[x] + D_p*L_p);
		}
		t+= dt;
		abund(v, p);
		if(t >= a0){
			k++;
//			printf("%d %.1f\n", k, t);
			op(k, v, p);
			a0+= q;
		}
	}

	free(v);
	free(p);
	return 0;
}

void abund(double *v, double *p){
	double cv=0.0, cp=0.0;
	int i;
	FILE *arq;
	arq= fopen("dat/abund.dat", "a");

	for(i = 0; i < Nx; i++){
		cv+= v[i];
		cp+= p[i];
	}
	fprintf(arq, "%e %e ", cv/(Nx), cp/(Nx));
	fprintf(arq, "\n");

	fclose(arq);
}
