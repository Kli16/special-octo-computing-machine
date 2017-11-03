#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
  DIR* d;
  d = opendir(".");

  printf("\nThese are the Files:\n");
  struct dirent* entry;
  while((entry = readdir(d))){
    if((*entry).d_type == DT_REG){
      printf("%s\n",(*entry).d_name);
    }
  }

  closedir(d);

  d = opendir(".");

  printf("\nThese are the Directories:\n");
  while((entry = readdir(d))){
    if((*entry).d_type != DT_REG){
      printf("%s\n",(*entry).d_name);
    }
  }

  closedir(d);

  d = opendir(".");
  printf("\nDirectory size:\n");
  int bytes = 0;
  struct stat file;
  while((entry = readdir(d))){
    stat((*entry).d_name,&file);
    bytes += file.st_size;
  }
  printf("%d\n",bytes);

  closedir(d);

  return 0;
}
