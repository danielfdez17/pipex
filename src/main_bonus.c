/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:25 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex_bonus.h"

/**
 * Main function that creates two child processes
 * to execute the commands received in @param av
 */
// int	main(int ac, char **av, char **envp)
// {
// 	// int	fd_read;
// 	// int	fd_write;
// 	int	status;
// 	int	i;
// 	int	fds[2];
// 	pid_t pid1, pid2, pid3;
// 	(void)pid2;

// 	if (ac < 5)
// 		return (0);
// 	if (pipe(fds) == -1)
// 		error();
// 	pid1 = fork();
// 	if (pid1 < 0)
// 		error();
// 	if (pid1 == 0)
// 		run_first_cmd(av, fds, envp);

// 	// ft_dup2(fd_read, STDIN_FILENO);
// 	// ! este bucle lo puede hacer un pid3, como la lectura y escritura
// 	// pid2 = fork();
// 	// if (pid2 < 0)
// 	// 	error();
// 	i = 3;
// 	// if (pid2 == 0)
// 	// {
// 		while (i < ac - 2)
// 			run_i_cmd(av, envp, i++);
// 	// }
// 	pid3 = fork();
// 	if (pid3 < 0)
// 		error();
// 	if (pid3 == 0)
// 		run_last_cmd(ac, av, fds, envp);
// 	// fd_read = open_read_file(av[1]);
// 	// fd_write = open_write_file(av[ac - 1]);
// 	// if (pipe(fds) < 0)
// 	// 	error();
// 	// ft_calloc(sizeof(char *), 10);
// 	// return (0);

// 	// run_command(av[ac - 2], envp);
// 	close_fds(fds);
// 	waitpid(pid1, &status, 0);
// 	// waitpid(pid2, &status, 0);
// 	waitpid(pid3, &status, 0);
// 	if (WIFEXITED(status))
// 		exit(WEXITSTATUS(status));
// 	return (0);
// }

void	init_pipe_ends(int fds[2])
{
	fds[0] = -1;
	fds[1] = -1;
}

int main(int ac, char **av, char **envp)
{
    int     i;
    int     pipe_prev[2];
    int     pipe_curr[2];
    pid_t   pid;
    int     infile;
    int     outfile;

    if (ac < 5)
        error();

    infile = open(av[1], O_RDONLY);
    if (infile < 0)
	{
        perror(av[1]);
		infile = open("/dev/null", O_RDONLY);
	}

    outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0)
        error();

    // pipe_prev no existe todavía
	init_pipe_ends(pipe_prev);

    i = 2;
    while (i < ac - 1)
    {
        if (i != ac - 2) // no es el último comando
        {
            if (pipe(pipe_curr) < 0)
                error();
        }

        pid = fork();
        if (pid < 0)
            error();

        if (pid == 0)
        {
            /* ----- CHILD ----- */

            // Si existe una pipe anterior: conectar a STDIN
            if (pipe_prev[0] != -1)
            {
                dup2(pipe_prev[0], STDIN_FILENO);
            }
            else
            {
                dup2(infile, STDIN_FILENO);
            }

            // Si no es el último comando: redireccionar STDOUT al pipe nuevo
            if (i != ac - 2)
            {
                dup2(pipe_curr[1], STDOUT_FILENO);
            }
            else
            {
                dup2(outfile, STDOUT_FILENO);
            }

            // Cerrar restos en child
            if (pipe_prev[0] != -1)
                close(pipe_prev[0]);
            if (pipe_prev[1] != -1)
                close(pipe_prev[1]);

            if (i != ac - 2)
            {
                close(pipe_curr[0]);
                close(pipe_curr[1]);
            }

            close(infile);
            close(outfile);

            run_command(av[i], envp);
            exit(1);
        }

        /* ----- PARENT ----- */

        // cerrar pipe anterior
        if (pipe_prev[0] != -1)
            close(pipe_prev[0]);
        if (pipe_prev[1] != -1)
            close(pipe_prev[1]);

        // mover pipe_curr a pipe_prev
        if (i != ac - 2)
        {
            pipe_prev[0] = pipe_curr[0];
            pipe_prev[1] = pipe_curr[1];
        }

        i++;
    }

    // cerrar pipes finales
    if (pipe_prev[0] != -1) close(pipe_prev[0]);
    if (pipe_prev[1] != -1) close(pipe_prev[1]);

    close(infile);
    close(outfile);

    // esperar a todos los hijos
    while (wait(NULL) > 0)
        ;

    return (0);
}
