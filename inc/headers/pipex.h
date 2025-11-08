#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/inc/headers/libft.h"
# include "../libft/inc/headers/ft_printf.h"

# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif

typedef short int t_bool;


// * ERROR HANDLING

// * PIPES HANDLING
void	pipex(int ac, char **av, int fd_read, int fd_write);

// * FILES HANDLING
void	close_fds(int *fds);
int		open_read_file(char *filename);
int		open_write_file(char *filename);

// * MEMORY HANDLING
void	free_split(char **split);

// * COMMANDS HANDLING
char	*get_exetuable(char *program_name);
t_bool	validate_commands(int ac, char **av);

#endif // PIPEX_H