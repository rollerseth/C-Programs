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

  long count = 0;
  long counter = 0;

  long max;
  //max = calloc(atol(argv[1], sizeof(long)));
  //max = malloc(atol(argv[1]) * sizeof(long));
  long newMax;
  
  
  max = atol(argv[1]);
  newMax = sqrt(*max);
  char *prime = malloc(*max + 1);

  

  // initializes everything to true for prime
  for (long i = 2; i <= newMax; i++) {
    prime[i] = 1;
  }

  long i = 2;

  while (i <= newMax)
  {
    for (long j = 2 * i; j <= newMax; j += i) {
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

  long theNums[count];
  
  
  for (long b = 2; b <= newMax; b++) {
    if (prime[b]) {

      theNums[counter] = b;
      counter++;
    }
  }

  long q = 0;
  long tempMax = *max;
  long numsCount[count];
  long record = 0;
  
  while (count > q) {

    if (tempMax % theNums[q] == 0) {
      tempMax = tempMax / theNums[q];
      record++;
    }

    else {
      numsCount[q] = record;

      if (record != 0) {
	printf("%d^%d ", theNums[q], numsCount[q]);
      }
      
      record = 0;
      q++;

    } // end of else
    
        
  } // end of while

  if (tempMax != 1)
    printf("%ld", tempMax);
  
  printf("\n");
  
}


