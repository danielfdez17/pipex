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

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *av, ...);
int		ft_put_char(char c);
int		ft_put_str(char *s);
int		ft_put_hex(unsigned int n, char format);
int		ft_put_ptr(unsigned long n);
int		ft_put_int(int n);
int		ft_put_uint(unsigned int n);
int		ft_tolower(int c);
char	ft_get_hex_value(int n);

#endif