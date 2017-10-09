#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  int tf = 0;
  if (!validate_cd_argv(argc, argv))
    return -1;

  else {
	tf = chdir(argv[1]);
	if(tf == -1) return -1;
	if(tf ==  0) return  0;
  }
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
  else{
	char CD[256] = {0,};
	getcwd(CD, 256);
	printf("%s\n", CD);
	return 0;
  }
}

int validate_cd_argv(int argc, char** argv) {
  if ((strcmp(argv[0], "cd")) == 0 && argc == 2)
    return 1;
  else
    return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  if ((strcmp(argv[0], "pwd")) == 0 && argc == 1 )
    return 1;
  else
    return 0;
}
