/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:07 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/16 19:25:33 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_int(int n)
{
	long	nb;
	int		printed;

	nb = n;
	printed = 0;
	if (nb < 0)
	{
		ft_put_char('-');
		++printed;
		nb = -nb;
	}
	if (nb >= 10)
	{
		printed += ft_put_int(nb / 10);
		printed += ft_put_int(nb % 10);
		return (printed);
	}
	return (ft_put_char(nb + '0') + printed);
}
