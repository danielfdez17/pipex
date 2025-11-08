#include "../inc/headers/pipex.h"

t_bool	validate_commands(int ac, char **av)
{
	int		i;
	char	*executable;
	char	**cmd;
	int		access_res;
	
	i = 2;
	while (i < ac - 1)
	{
		cmd = ft_split(av[i], ' ');
		if (!cmd)
		{
			ft_printf("Could not split argv in %s\n", __func__);
			return (FALSE);
		}
		executable = get_exetuable(cmd[0]);
		access_res = access(executable, F_OK);
		free(executable);
		free_split(cmd);
		if (access_res != 0)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
