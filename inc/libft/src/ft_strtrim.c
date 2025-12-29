/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:53 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/10 08:39:20 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	char const	*ptr;

	ptr = set;
	while (*ptr)
	{
		if (c == *ptr++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_is_in_set(s1[start], set) == 1 && start <= end)
		++start;
	while (ft_is_in_set(s1[end], set) == 1 && end >= start)
		--end;
	return (ft_substr(s1, start, end - start + 1));
}

// #include <stdio.h>
// int main(void)
// {
// 	char *result;
// 	printf("%s|\n---\n", 
// (	result = ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " ")));
// 	printf("%s|\n---\n", ft_strtrim("lorem ipsum dolor sit amet", "te"));
// 	printf("%s|\n---\n", ft_strtrim(" lorem ipsum dolor sit amet", "l "));
// 	printf("%s|\n---\n", ft_strtrim("lorem ipsum dolor sit amet", "tel"));
// 	printf("%s|\n---\n", ft_strtrim("          ", " "));
// 	printf("%s|\n---\n", ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t"));
// 	printf("%s|\n---\n", ft_strtrim("", " \n\t"));
// 	printf("%s|\n---\n", ft_strtrim("   xxx   xxx", " x"));
// 	printf("%s|\n---\n", ft_strtrim("", ""));
// 	printf("%s|\n---\n", ft_strtrim("abcd", ""));
// 	printf("%s|\n---\n", ft_strtrim("", "cdef"));
// 	printf("%s|\n---\n", ft_strtrim(" . abcd", " "));
// 	printf("%s|\n---\n", ft_strtrim("ab cd  f    ", " "));
// 	printf("%s|\n---\n", 
// ft_strtrim("xxxz  test with x and z and x .  zx  xx z", "z x"));
// 	printf("%s|\n---\n", ft_strtrim("   abxfg  ", "x"));
// 	printf("%s|\n---\n", ft_strtrim(".teste, bla ,.,.", ",."));
// 	return (0);
// }
// // ccw ft_strtrim.c ft_strlen.c ft_substr.c ft_strdup.c -o a.out && ./a.out