// Author: Seth Roller

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>


long reverse(long n)
{
  long hold = 0;

  while (n > 0) {

    long remain = n % 10;
    hold = hold * 10 + remain;
    n /= 10;
    
  }

  return hold;
}

int ispalindrome(long n)
{
  long rev = reverse(n);
  
  if (n == rev)
    return 1;
  
  else
    return 0;

}

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    fprintf(stderr, "Usage Error: Need 1 command line argument.\n");
    exit(1);
  }
  
  long n = atol(argv[1]);
  for (long i = 0; i <= n; i++)
  {
    long call = i * i;
    int receive = ispalindrome(call);

    if (receive == 1)
      printf("%ld: %ld\n", i, i * i);
  }

}
