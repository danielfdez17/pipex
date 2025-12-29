/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:07 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/16 19:25:33 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_uint(unsigned int n)
{
	unsigned long	nb;
	int				printed;

	nb = n;
	printed = 0;
	if (nb >= 10)
	{
		printed += ft_put_uint(nb / 10);
		printed += ft_put_uint(nb % 10);
		return (printed);
	}
	return (ft_put_char(nb + '0') + printed);
}
