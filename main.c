#include "main.h"

/**
 * pprompt - this function is used to display the prompt
 * @x : character that refers to $
 * Return: 0 on success
 */

char pprompt(char *x)
{
	x = "$";

	printf("%s", x);
	return (0);
}

/**
 * user_input - this function allows user to enter command
 * @command: user's entered command
 * @array: command size
 * Return: void.
 */

void user_input(char *command, size_t array)
{
	if (fgets(command, array, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_putchar('\n'); /**putchar required**/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
/**
 * execution - this function is used to execute command files from the root
 * @cmd: command
 * Return: 0.
 */

char execution(const char *cmd)
{
	pid_t process = fork();

	if (process < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (process == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

/**
 * main - Entry point
 * @argv: standard input (stdin)
 * @argc: number of arguments
 * Return: 0 on success
 */

int main(int argc, char *arv[])
{

	while (1)
	{
		pprompt();
		user_input();
		execution();
	}
	return (0);
}
