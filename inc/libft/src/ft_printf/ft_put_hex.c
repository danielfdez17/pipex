/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:53:56 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/21 11:02:59 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Obtains the letter from n 
 * @return {A, B, C, D, E, F, G}
 */
char	ft_get_hex_value(int n)
{
	if (n >= 0 && n < 10)
		return (n + 48);
	return (65 + n - 10);
}

static int	ft_print(unsigned long ptr, int is_upper)
{
	int	printed;

	printed = 0;
	if (ptr > 15)
	{
		printed += ft_print(ptr / 16, is_upper);
		printed += ft_print(ptr % 16, is_upper);
		return (printed);
	}
	if (!is_upper)
		return (printed + ft_put_char(ft_tolower(ft_get_hex_value(ptr))));
	return (printed + ft_put_char(ft_get_hex_value(ptr)));
}

int	ft_put_hex(unsigned long n, char format)
{
	int	printed;
	int	is_upper;

	printed = 0;
	is_upper = 0;
	if (format == 'p')
	{
		if (n == 0)
			return (ft_put_str("(nil)"));
		printed += ft_put_str("0x");
	}
	else if (format == 'X')
		is_upper = 1;
	printed += ft_print(n, is_upper);
	return (printed);
}
