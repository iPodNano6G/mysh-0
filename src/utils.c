#include <string.h>
#include <stdlib.h>
#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{	
	(*argv) = (char **) malloc(sizeof(char*)*4096);
	for(int i =0; i < 4096; i++) {
		*(*argv+i) = (char*)malloc(sizeof(char)*4096);
	}
	char* test = (char*)malloc(sizeof(char)*4096);
	char* temp = (char*)malloc(sizeof(char)*4096);

	strcpy(test, command);

	temp = strtok(test, " \n\t");
	int j = 0;
	
	if(temp == NULL) {
		strcpy(*(*argv+j), "");
		j++;
	}

	while (temp != NULL) {
		strcpy(*(*argv+j), temp);
		j = j + 1;
		temp = strtok(NULL, " \n\t");
	}

	*argc = j;
	free(test);
	free(temp);
}
