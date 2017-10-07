#include <string.h>
#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char* temp = strtok((char*)command, " ");
	int i = 0;
	char* ARGV[] = {NULL};

	while (temp != NULL) {
		ARGV[i] = temp;
		argv[i] = &ARGV[i];
		i = i + 1;
		temp = strtok(NULL, " ");
	}
	argc = &i;
}
