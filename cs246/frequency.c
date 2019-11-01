// Author: Seth Roller

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

enum state {
  IN_WORD, NOT_IN_WORD
};

struct item {
  char *word;
  int count;
};

int comparSort(const void * first, const void * sec)
{
  // pass two structs that point to their respective counts

  struct item *we = (struct item *) first;
  struct item *are = (struct item *) sec;

  if (we->count > are->count)
    return -1;

  else if (we->count < are->count)
    return 1;
  
  else
    return 0; 
}

int comparSearch(const void * first, const void * sec)
{
  // pass a string and a struct item

  char *we = (char *) first;
  struct item *are = (struct item *) sec;

  return strcmp(we, are->word);
      
}

void reading(FILE *in, struct item *a, int *arrayC)
{
  int c;
  int count = 0;
  char limit[257];
   
  enum state state = NOT_IN_WORD;

  while ((c = fgetc(in)) != EOF) {
    
    switch (state) {
    case IN_WORD:
      if (!isalpha(c)) {
	limit[count] = '\0';
	state = NOT_IN_WORD;

	struct item *found = bsearch(limit, a, (*arrayC), sizeof(struct item),
				comparSearch);

	if ((*arrayC) == 0) {
        a[0].word = strdup(limit);
        a[0].count = 1;
        (*arrayC)++;
	
    }


	if (found != NULL)
	{
	  found->count++;
	}

	else {
	  int i = (*arrayC) - 1;
	  
	  while (i != -1)
	  {
	    if (strcmp(a[i].word, limit) > 0)
	    {
	      a[i + 1] = a[i];
	      i--;
	    }
	    else
	      break;
	  }
	  
	  a[i + 1].word = strdup(limit);
	  a[i + 1].count = 1;
	  (*arrayC)++;
	}
	
	count = 0;
	*limit = '\0';
      } // end of if !isalpha
      
      break;
      
    case NOT_IN_WORD:
      if (isalpha(c)) {
	
	state = IN_WORD;
      }
   
      break;
    } // end of switch

    if (isalpha(c)) {
      c = tolower(c);
      limit[count++] = c;

    }

  } // end of while

}

int main(int argc, char *argv[])
{
  int theCount = 0;
 // int *y = &theCount;
  struct item a[100000];
  
  // reads from stdin
  if (argc == 1)
  {
    reading(stdin, a, &theCount);
  }
  
  else
  {
    for (int i = 1; i < argc; i++)
      {
	FILE *in = fopen(argv[i], "r");
	
	if (in == NULL)
	{
	  fprintf(stderr, "%s: %s: %s:\n", argv[0],argv[i],strerror(errno));
	}

	reading(in, a, &theCount);
	
      } // end of loop
    
  }

  qsort(a, theCount, sizeof(struct item), comparSort);

  for (int i = 0; i < theCount; i++)
  {
      printf("%s: %d\n", a[i].word, a[i].count);
  }
  

}


