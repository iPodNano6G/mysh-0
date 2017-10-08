#include <string.h>
#include <stdlib.h>
#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char* temp = strtok((char*)command, " \n");
	int i = 0;
	
	(*argv) = (char **) malloc(sizeof(char*)*32);

	for(int i =0; i < 32; i++) {
		(*argv)[i] = (char*)malloc(sizeof(char)*128);
		strcpy((*argv)[i], "");
	}

	while (temp != NULL) {
		strcpy((*argv)[i], temp);
		i = i + 1;
		temp = strtok(NULL, " \n");
	}

	*argc = i;
}
