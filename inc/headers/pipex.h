#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/inc/headers/libft.h"
# include "../libft/inc/headers/ft_printf.h"

# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif

typedef short int t_bool;

typedef struct s_pipex
{
	int	fds[2];
	pid_t	pid1;
	pid_t	pid2;
	char 	*cmd1;
	char 	*cmd2;
	char 	**envp;
}	t_pipex;


// * ERROR HANDLERS
void	error(void);

// * PIPES HANDLERS
// void	pipex(int ac, char **av, int fd_read, int fd_write);

// * FILES HANDLERS
void	ft_dup2(int oldfd, int newfd);
void	close_fds(int *fds);
int		open_read_file(char *filename);
int		open_write_file(char *filename);

// * PATH HANDLERS
char	*get_path(char *cmd, char *envp[]);
int	cmd_have_path(char *cmd);
int	cmd_have_current_path(char *cmd);

// * MEMORY HANDLERS
void	free_split(char **split);

// * COMMANDS HANDLERS
void	run_command(char *cmd, char *envp[]);
// void	run_command(char *cmd, char **envp);
void	run_i_child(t_pipex *data, int infile, char *envp[]);
// void	run_i_child(t_pipex *pipex, int fd_read);
void	run_last_child(t_pipex *data, int outfile, char *envp[]);
// void	run_last_child(t_pipex *pipex, int fd_write);
char	*get_exetuable(char *program_name);
t_bool	validate_commands(int ac, char **av);

#endif // PIPEX_H