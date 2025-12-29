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

int	ft_print_hex(unsigned int n, int is_upper)
{
	int	printed;

	printed = 0;
	if (n > 15)
	{
		printed += ft_print_hex(n / 16, is_upper);
		printed += ft_print_hex(n % 16, is_upper);
		return (printed);
	}
	if (!is_upper)
		return (printed + ft_put_char(ft_tolower(ft_get_hex_value(n))));
	return (printed + ft_put_char(ft_get_hex_value(n)));
}

int	ft_put_hex(unsigned int n, char format)
{
	int	printed;
	int	is_upper;

	printed = 0;
	is_upper = 0;
	if (format == 'X')
		is_upper = 1;
	printed += ft_print_hex(n, is_upper);
	return (printed);
}
