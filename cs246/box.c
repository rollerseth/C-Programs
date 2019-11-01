// Author: Seth Roller

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[]) {
	
  srand(time(NULL));
  printf("%lf %lf\n\n\n",drand48(), drand48());
  int n = atoi(argv[1]);
  int b;

  b = n - 2;
  
  for (int i = 1; i <= n; i++)
    printf("*");
  printf("\n");

  // found how to format this in 'man 3 printf'
  for (int j = 1; j <= b; j++)
    printf("%s %*s\n", "*", b, "*");
  
  for (int i = 1; i <= n; i++)
    printf("*");
  printf("\n");
  
}
