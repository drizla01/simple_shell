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

	free(line_buffer);

	char *arguments[] = {arg, NULL};

	int fork_ntimes = 1;

	for ( int fork_count = 0; fork_ntimes; fork_count++)
	{
		printf("FORK number %d!\n", fork_count + 1);
		child_pid = fork();


		if (child_pid == -1)
		{
			perror("Failed to create child process");
			return (1);
		}
		else if (child_pid > 0)
		{
			puts("WAITS");
			wait(&wait_status);
			puts("RESUMED FROM WAIT");
		}

		else if (child_pid == 0)
		{
			puts("I am forked child, to execute another program now");

			execve(arguments[0], arguments, NULL);
		}
	}
}
