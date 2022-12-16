#include "simple_shell.h"

int main()
{
	pid_t child_pid;
	int wait_status;

	size_t argument_length;
	char *line_buffer;

	printf("Shell  $ ");
	getline(&line_buffer, &argument_length, stdin);

	for (argument_length = 0; line_buffer[argument_length] != '\n'; argument_length++);

	int i = 0;

	char *arg = malloc(argument_length * sizeof(char));

	for (i = 0; ; i++)
	{
		arg[i] = line_buffer[i] != '\n' ? line_buffer[i] : '\0';
		if (line_buffer[i] == '\n')
		break;
	}
}
