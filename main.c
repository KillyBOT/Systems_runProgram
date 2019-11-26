#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char** parseArgs(char* line){
  char* newLine = line;
  char** args = malloc(strlen(line) * sizeof(char));
  int p = 0;
  do{
    args[p] = strsep(&newLine, " ");
    p++;
  } while ( strlen(newLine)  != 0);

  args[p] = NULL;
  p++;

  return args;
}

int main(int argc, char* argv[]){

  char** args;
  char argsToCall[64] = "ls -l -a";

  args = parseArgs(argsToCall);
  for(int x = 0; x < 3; x++){
    printf("%s\n", args[x]);
  }

  execvp(args[0],args);
  return 0;
}
