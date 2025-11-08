/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:24 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 12:21:58 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;
	t_list	*prev;

	ptr = lst;
	prev = NULL;
	while (ptr != NULL)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	return (prev);
}
