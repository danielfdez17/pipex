/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:55 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/07 09:53:14 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *litle, size_t len)
{
	size_t	i;
	size_t	j;

	if (litle[0] == '\0')
		return (&big[0]);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == litle[j] && i + j < len)
		{
			if (litle[j + 1] == '\0')
				return (&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <bsd/string.h>
// int main(void)
// {
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("Foo Bar Baz", "Bar", 4));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("Foo Bar Baz", "Bar", 4));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("lorem ipsum dolor sit amet", "sit", 10));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("lorem ipsum dolor sit amet", "sit", 10));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("lorem ipsum dolor sit amet", "ipsum", 15));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("lorem ipsum dolor sit amet", "dol", 30));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("lorem ipsum dolor sit amet", "dol", 30));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("abcdefgh", "abc", 2));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("abcdefgh", "abc", 2));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("abcdefgh", "abc", 3));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("abcdefgh", "abc", 3));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("abc", "abcdef", 2));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("abc", "abcdef", 2));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("aaxx", "xx", 2));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("aaxx", "xx", 2));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("aaxx", "xx", 3));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("aaxx", "xx", 3));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("abcdefgh", "abc", 4));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("abcdefgh", "abc", 4));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("abcdefgh", "abc", 5));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("abcdefgh", "abc", 5));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("aaxx", "xx", 4));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("aaxx", "xx", 4));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("aaxx", "xx", 5));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("aaxx", "xx", 5));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("aaxx", "xx", 6));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("aaxx", "xx", 6));
// 	// ("aaxx", "xx", 6) -> xx
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("abc", "abc", 7));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("abc", "abc", 7));
// 	printf("ft_strnstr: %s\n",
// 		 ft_strnstr("abcdef", "abc\375xx", 3));
// 	printf("   strnstr: %s\n---\n",
// 		 strnstr("abcdef", "abc\375xx", 3));
// 	return (0);
// }
// // ccw -lbsd ft_strnstr -o a.out && ./a.out