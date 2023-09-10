#include <stdlib.h> 
 
#include <stdio.h> 
 
#include <sys/time.h> 
#include <time.h> 
 
 
void get_walltime (double* wcTime ) { 
 
struct timeval tp ; 
 
gettimeofday(&tp ,NULL) ; 
 
*wcTime=(tp.tv_sec + tp.tv_usec/1000000.0) ; 
 
} 
 
 
 
int main (int argc, char* argv []) { 
 
int i, j, k, n=5000, a; 
 
int ** matrizA, **matrizB, **matrizC; 
 
double S1, E1 ; 
 
 
 
// I n i c i a l i z a n d o m a t ri c e s 
 
matrizA = (int **)malloc(n*sizeof(int *)); 
 
for ( i =0; i<n ; i++) 
 
*(matrizA+i) = (int *) malloc(n*sizeof(int)); 
 
 
matrizB = (int **)malloc(n*sizeof(int *)); 
 
for ( i =0; i<n ; i++) 
 
*(matrizB+i) = (int *) malloc(n*sizeof(int)); 
 
 
matrizC = (int **)malloc(n*sizeof(int *)); 
 
for ( i =0; i<n ; i++) 
 
*(matrizC+i) = (int *) malloc(n*sizeof(int)); 
//Llenando m a t ri c e s 
 
for (i=0; i<n; ++i) 
 
{ 
 
for (j=0; j<n; ++j) 
 
{ 
 
matrizA[i][j] = rand( ) %6; 
matrizB[i][j] = rand( ) %6; 
 
} 
 
} 
 
printf("llenas matrices\n");
 
 
get_walltime(&S1); 
 
for (k=0; k<n; ++k) 
 
{ 
 
for (j=0; j<n; ++j) 
 
{ 
 
for (i = 0; i<n; ++i) 
 
{ 
 
matrizC[i][j]+= matrizA[i][k]*matrizB[k][j] ; 
 
} 
 
} 
printf("valor de k: %d\n", k);
} 
 
get_walltime(&E1); 
 
 
 
printf("Tiempo m�todo kji: %f s\n", (E1-S1)) ; 
scanf("%d", &a);
return 0; 
 
}
