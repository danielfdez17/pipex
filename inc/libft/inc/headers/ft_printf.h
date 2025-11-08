/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:34:56 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/21 10:59:30 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(char const *av, ...);
int	ft_put_char(char c);
int	ft_put_str(char *s);
int	ft_put_hex(unsigned long n, char format);
int	ft_put_int(int n);
int	ft_put_uint(unsigned int n);

#endif