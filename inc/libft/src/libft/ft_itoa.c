/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:13 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/07 11:10:12 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_get_len(int n)
// {
// 	int		i;
// 	long	ln;

// 	i = 0;
// 	ln = n;
// 	if (n == 0)
// 		return (1);
// 	if (n < 0)
// 		++i;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		++i;
// 	}
// 	if (n < 0)
// 	{
// 		while (n < 0)
// 		{
// 			n /= 10;
// 			++i;
// 		}
// 		return (i + 1);
// 	}
// 	while (n > 0)
// 	{
// 		n /= 10;
// 		++i;
// 	}
// 	return (i);
// }

// Todo: test 
static int	ft_get_len(int n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		++i;
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static char	*ft_reverse(char *s)
{
	size_t	start;
	size_t	end;
	char	c;

	start = 0;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		c = s[start];
		s[start] = s[end];
		s[end] = c;
		++start;
		--end;
	}
	return (s);
}

static char	*ft_solve(int n, char *result)
{
	long	nb;
	int		i;
	int		is_negative;

	i = 0;
	nb = n;
	is_negative = 0;
	if (nb < 0)
	{
		nb = -nb;
		is_negative = 1;
	}
	while (nb > 0)
	{
		result[i] = (nb % 10) + '0';
		++i;
		nb /= 10;
	}
	if (is_negative == 1)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_reverse(result));
}

char	*ft_itoa(int n)
{
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	result = malloc(sizeof(char) * (ft_get_len(n) + 1));
	if (!result)
		return (NULL);
	return (ft_solve(n, result));
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (ac-- > 1)
// 	{
// 		printf("ft_itoa(%d): %s\n", atoi(av[i]), ft_itoa(atoi(av[i])));
// 		++i;
// 	}
// 	return (0);
// }
// ccw ft_itoa.c ft_strdup.c ft_strlen.c -o a.out
// && ./a.out 0000 123 -123 45123456789876543