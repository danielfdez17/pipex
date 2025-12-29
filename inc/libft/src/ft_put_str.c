/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:47:26 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/21 08:59:22 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *s)
{
	int	size;

	if (!s)
		return (ft_put_str("(null)"));
	size = 0;
	while (s[size])
		ft_put_char(s[size++]);
	return (size);
}
