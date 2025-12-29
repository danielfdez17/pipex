/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:48 by danfern3          #+#    #+#             */
/*   Updated: 2025/12/29 08:24:42 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static int	ft_issign(const char *s, size_t i, int *p_counter, int *n_counter)
{
	if (s[i] == '-')
	{
		*n_counter += 1;
		return (1);
	}
	if (s[i] == '+')
	{
		*p_counter += 1;
		return (1);
	}
	return (0);
}

static int	isnumber(const char *s, size_t i, int *result)
{
	if (ft_isdigit(s[i]))
	{
		*result = *result * 10 + (s[i] - '0');
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		result;
	int		p_counter;
	int		n_counter;
	size_t	i;

	result = 0;
	p_counter = 0;
	n_counter = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		++i;
	if (ft_issign(nptr, i, &p_counter, &n_counter))
		++i;
	if (n_counter > 1 || p_counter > 1 \
		|| (n_counter >= 1 && p_counter >= 1))
		return (0);
	while (isnumber(nptr, i, &result))
		++i;
	if (n_counter == 1)
		return (-result);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (--ac)
// 	{
// 		printf("ft_atoi: %d\n", ft_atoi(av[i]));
// 		printf("atoi: %d\n---\n", atoi(av[i]));
// 		assert(ft_atoi(av[i]) == atoi(av[i]));
// 		++i;
// 	}
// 	return (0);
// }