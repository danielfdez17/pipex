/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:27 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 12:21:58 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*aux;

	ptr = *lst;
	while (ptr)
	{
		aux = ptr;
		ptr = ptr->next;
		ft_lstdelone(aux, del);
	}
	*lst = NULL;
}
