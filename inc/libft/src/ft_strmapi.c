/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:57 by danfern3          #+#    #+#             */
/*   Updated: 2025/12/29 07:57:33 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		++i;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>
// char	ft_modify(unsigned int i, char c)
// {
// 	(void)i;
// 	return (ft_toupper(c));
// 	// return (ft_tolowerd(c));
// }
// int main()
// {
// 	char const *s = "hola BUENOS dias234";
// 	printf("before: %s, \nafter: %s\n", s, ft_strmapi(s, ft_modify));
// 	return 0;
// }
