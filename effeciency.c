#include <stdio.h>
#include <time.h>
#include <cblas.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
  clock_t start, end;
  double cpu_time_used;
     
  start = clock();
  
//float dotProduct(int n, double x[], double y[]) {
//	float result = 0.0;
//	for(int i = 0; i<n; i++){
//	result += x[i] * y[i];
//	}
//	return result;


  // x and y are the two vectors that we will use
 //double x[5]= {1,-1,1,-1,1}; loop it rather since we are using more than 5 
  //double y[5] = {-1,1,-1,1,-1}; same here
      int n  = atoi(argv[1]);// input your argument after ./ip
  // x and y are the two vectors that we will use
  double *x =  malloc(sizeof(double) * n);
  double *y =  malloc(sizeof(double) * n);
  
 for(int i =0; i< n;i++){
    if(i%2==0)
    x[i] =  1.0;
    else
    x[i] = -1.0;
 }
 for(int i =0; i< n;i++){
    if(i%2==1)
    y[i] =  1.0;
    else
    y[i] = -1.0;
 }
  // This is the call to the BLAS function.  
  // See the BLAS documentation for other functions and
  // the definition of the arguments
  // In this case, the first argument is the length of the
  // vectors, and the 3rd and 5th arguments are the increments
  // to use when traversing the vectors.
  //double dotprod = cblas_ddot(5, x, 1, y, 1);
  double result = cblas_ddot(n, x,1, y,1);
  // print the result
  printf("%lf\n", result);

 
  //end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  // print the result
  printf("This task took %f seconds to execute \n", cpu_time_used);

  return 0.;
}

