// Author: Seth Roller

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void comprehending(char *arguments, int space)
{
  DIR *dir = opendir(arguments);
  if (dir == NULL) {

    fprintf(stderr, "%s: %s\n", arguments,strerror(errno));
    return;
  }
  char *copy;

  struct dirent *dirp;

  while ((dirp = readdir(dir)) != NULL) {

    if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0)
    {
      printf("%*s",space,""); 
      printf("|- %s\n",dirp->d_name);
      
      copy = malloc(strlen(arguments) + strlen(dirp->d_name) + 2);
      strcpy(copy, arguments);
      strcat(copy,"/");
      strcat(copy, dirp->d_name);
      copy[(strlen(arguments) + strlen(dirp->d_name) + 1)] = '\0';
      
      struct stat path_name;
      stat(copy, &path_name);

      if (S_ISDIR(path_name.st_mode))
      {
	comprehending(copy, space + 4);
      }

      free(copy);
    } // end of first if
    
  } // end of while
  closedir(dir);

}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s directory\n", argv[0]);
    exit(1);
  }
  printf("%s\n", argv[1]);
  comprehending(argv[1], 0);
  
}
