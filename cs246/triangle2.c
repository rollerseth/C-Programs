// Author: Seth Roller

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>

void looping(int start, char diff);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "Usage message: You must have two arguments.\n");
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
    fprintf(stderr,"Usage message: Enter a number between 1 and 4.\n");
    exit(1);
  }
  
  switch (shape)
  {
    
  case 1:
    while (i <= size)
    {
      if (size < 4)
      {
	looping(count, '*');
	count++;
	i++;
      }
      
      else
      {
	// added 3 to account for 3 separate print statements 
	i += 3;
	// manipulated i so that this will run once
	printf("*\n**\n");
	for (int j = size - 3; j >= 1; j--)
	{
	  printf("*%*s\n",i - 2, "*"); 
	  i++;
	}
	//print bottom row
	for (int k = 0; k < size; k++)
	  printf("*");
	printf("\n");
	
      }
    }
    break;

  case 2:
    while (i <= size)
    {
      if (size < 4)
      {
	looping(sub, ' ');
	looping(count, '*');
	sub--;
	count++;
	i++;
      }
      
      else
      {
	i += 3;
	looping(sub - 1, ' ');
	printf("*\n");
	looping(sub - 2, ' ');
	printf("**\n");
	for (int j = size - 3; j>= 1; j--)
	{
	  looping(sub - 3, ' ');
	  printf("%s%*c%s\n","*",i - 3,' ',"*");
	  sub--;
	  i++;
	}
	
	for (int k = 0; k < size; k++)
	  printf("*");
	printf("\n");
	
      }// end of else
    }
    break;
    
  case 3:
    while (i <= size)
    {
      if (size < 4)
      {
	looping(sub, '*');
	sub--;
	i++;
      }
      else
      {
	i += 3;
	int y = size;
	for (int k = 0; k < size; k++)
	  printf("*");
	printf("\n");
	for (int j = size - 3; j >= 1; j--)
	{
	  printf("*%*s\n",y - 2, "*");
	  y--;
	  i++;
	}
	printf("**\n*\n");
	
      }
   
    }
    break;

  case 4:
    while (i <= size)
    {
      if (size < 4)
      {
      for (int j = count; j > 1; j--)
	printf(" ");
      looping(sub, '*');
      sub--;
      count++;
      i++;
      }

      else
      {
	for (int k = 0; k < size; k++)
	  printf("*");
	printf("\n");
	i += 3;
	int y = size;
	for (int j = size - 3; j >= 1; j--)
	{
	  printf("%*s %*s\n", count + 1, "*", y - 3, "*");
	  y--;
	  i++;
	  count++;
	}
	
	looping(sub - 2, ' ');
	printf("**\n");
	looping(sub - 1, ' ');
	printf("*\n");
	

      }
    }
     
  } // end of switch

  } //end of intial else

} // end of main


void looping(int start, char diff)
{

 for (int j = start; j >= 1; j--)
   printf("%c", diff);
 if (diff == '*')
   printf("\n"); 

}
