// Author: Seth Roller

# include <stdio.h>
# include <stdlib.h>

long power(long m, int n);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "Usage message error: need 2 arguments\n");
    exit(1);
  }
  
  long first = atoi(argv[1]);
  int second = atoi(argv[2]);

  printf("Powers of %ld\n\n", first);
  
  power(first, second);

}

long power(long m, int n)
{
  long output = m;

  printf("     1 %ld\n", m);
  for (int i = 2; i <= n; i++)
    {
      output *= m;
      printf("    %2d %ld\n", i, output);

    }
  
  return output;
 
}
