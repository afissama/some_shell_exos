#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void exec_prog();
int call_child(int n);
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{

	call_child(5);
	return (0);
}


/**
 * call_child - create child process
 * 
 * @param n 
 * @return int 
 */
int call_child(int n)
{
	if (n == 0)
	{
		exit(0);
	}
	
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		exec_prog();
	}
	else
	{
		wait(&status);
		call_child(n-1);
	}
}

/**
 * exec_prog - exec program
 * 
 */
void exec_prog()
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
}