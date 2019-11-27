#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char** parseArgs(char* line){

  char** args = malloc(sizeof(char) * 6);
  int p = 0;

  while (*line != '\0'){
    args[p] = strsep(&line, " ");
    p++;
  }

  args[p] = NULL;
  p++;

  return args;
}

int main(int argc, char* argv[]){

  char** args;
  char argsToCall[256];

  for(int x = 1; x < argc; x++){
    strcat(argsToCall,argv[x]);
    strcat(argsToCall," ");
  }

  args = parseArgs(argsToCall);

  execvp(args[0],args);

  free(args);
  return 0;
}
