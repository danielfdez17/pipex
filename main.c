

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
// #include <sys/wait.h>

// * Forks and pipe
// int main(void)
// {
// 	int	pipefds[2]; // 0 -> read; 1 -> write
// 	char buffer[256] = { 0 };

// 	printf("parent pid: %d\n", getpid());
// 	pipe(pipefds);
// 	write(pipefds[1], "msg", 3);
// 	// * If new process has been created, parent process ends
// 	if (fork() > 0)
// 		return (0);
// 	// ? Only executable for child process
// 	read(pipefds[0], buffer, 3);
// 	printf("got from pipe: %s\n", buffer);
// 	printf("child pid: %d\n", getpid());
// 	return (0);
// }

static void	close_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

// * Pipe (|) simulation
int main(void)
{
	int fds[2];

	if (pipe(fds) == -1)
		return (1);
	int pid1 = fork();
	if (pid1 < 0)	
		return (2);
	if (pid1 == 0)
	{
		char *av[] = {"ls", "-l", NULL};
		char *env[] = {NULL};
		// Child process one (ls -l)
		dup2(fds[1], STDOUT_FILENO);
		close_fds(fds);
		if (execve("/usr/bin/ls", av, env) == -1)
			perror("Could not execute execve");
	}
	int pid2 = fork();
	if (pid2 < 0)
		return (4);
	if (pid2 == 0)
	{
		char *av[] = {"wc", "-l", NULL};
		char *env[] = {NULL};
		// Child process two (wc -l)
		dup2(fds[0], STDIN_FILENO);
		close_fds(fds);
		if (execve("/usr/bin/wc", av, env) == -1)
			perror("Could not execute execve");
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	close_fds(fds);
	return (0);
}