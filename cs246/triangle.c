// Author: Seth Roller

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "You must have two arguments.\n");
    exit(1);
  }

  else
  {
  int shape = atoi(argv[1]);
  int size = atoi(argv[2]);
  int i = 1;
  int count = 1;
  int sub = size; 
  
  if (shape > 4 || shape < 1)
  {
    fprintf(stderr,"Enter a number between 1 and 4.\n");
    exit(1);
  }
  
  switch (shape)
  {
    
  case 1:
    while (i <= size)
    {
      for (int j = count; j >= 1; j--)
	printf("*");
      printf("\n");

      count++;
      i++;
    }
    break;

  case 2:
    while (i <= size)
    {
      for (int j = sub; j >= 1; j--)
	printf(" ");	
      
      for (int k = count; k >= 1; k--)
	printf("*");
      printf("\n");

      sub--;
      count++;
      i++;
    }
    break;
    
  case 3:
    while (i <= size)
    {
      for (int j = sub; j >= 1; j--)
	printf("*");
      printf("\n");

      sub--;
      i++;
      
    }
    break;

  case 4:
    while (i <= size)
    {
      for (int j = count; j > 1; j--)
	printf(" ");
      for (int k = sub; k >= 1; k--)
	printf("*");
      printf("\n");

      sub--;
      count++;
      i++;
    }
     
  } // end of switch

  } //end of else

}
