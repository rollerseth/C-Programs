// Author: Seth Roller

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long fib(int n);

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s: %s: %s\n",
	    argv[0],argv[1],strerror(errno));
    exit(1);
  }

  int number = atoi(argv[1]);
  for (int i = 0; i < number; i++)
    printf("%ld\n", fib(i));
  
  
}


long fib(int n)
{
  
  if (n == 0)
    return 0.0;

  else if (n == 1)
    return 1.0;
      
  else
    return (fib(n - 1) + fib(n - 2));
    
  
  
}
