/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:02 by danfern3          #+#    #+#             */
/*   Updated: 2025/12/29 08:24:50 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		++i;
	}
}

// #include <stdio.h>
// void	ft_modify(unsigned int i, char *c)
// {
// 	(void)i;
// 	char aux = *c;
// 	if (*c)
// 		aux = ft_tolower(aux);
// }
// int main()
// {
// 	char *s = "HOLA GUENAS234\0";
// 	printf("before: %s \nafter: ", s);
// 	ft_striteri(s, ft_modify);
// 	printf("%s\n", s);
// 	return 0;
// }
