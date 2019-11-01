// Author: Seth Roller

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(stderr, "usage: %s max\n", argv[0]);
    exit(1);
  }

  int count = 0;
  int counter = 0;

  long max; 
  long newMax;
  
  
  max = atol(argv[1]);
  newMax = sqrt(max);
  char *prime = malloc(newMax + 1);
  

  // initializes everything to true for prime
  for (long i = 2; i <= newMax; i++) {
    prime[i] = 1;
  }

  long i = 2;

  while (i <= newMax)
  {
    for (int j = 2 * i; j <= newMax; j += i) {
      prime[j] = 0;
    }
    
    i++;
    while (i <= newMax && !prime[i]) {
      i++;
    }
  }
  
  for (long i = 2; i <= newMax; i++) {
    if (prime[i]) {
      count++;
      //printf("%ld \n", i);
      
    }
  }

  long *theNums = calloc(count, sizeof(long));
  
  for (long b = 2; b <= newMax; b++) {
    if (prime[b]) {

      theNums[counter] = b;
      counter++;
    }
  }

  int q = 0;
  long tempMax = max;
  int numsCount[count];
  int record = 0;
  
  while (count > q) {

    if (tempMax % theNums[q] == 0) {
      tempMax = tempMax / theNums[q];
      record++;
    }

    else {
      numsCount[q] = record;

      if (record != 0) {
	printf("%ld^%d ", theNums[q], numsCount[q]);
      }
      
      record = 0;
      q++;

    } // end of else
    
        
  } // end of while

  if (tempMax != 1)
    printf("%ld", tempMax);
  
  printf("\n");
  
}


