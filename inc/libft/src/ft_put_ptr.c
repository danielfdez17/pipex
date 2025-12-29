/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
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

static int	ft_print_ptr(unsigned long n)
{
	int	printed;

	printed = 0;
	if (n > 15)
	{
		printed += ft_print_ptr(n / 16);
		printed += ft_print_ptr(n % 16);
		return (printed);
	}
	return (printed + ft_put_char(ft_tolower(ft_get_hex_value(n))));
}

int	ft_put_ptr(unsigned long n)
{
	int	printed;

	printed = 0;
	if (n == 0)
		return (ft_put_str("(nil)"));
	printed += ft_put_str("0x");
	return (printed + ft_print_ptr(n));
}
