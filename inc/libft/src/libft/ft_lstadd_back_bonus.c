/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:22 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 17:15:44 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = ft_lstlast(*lst);
	if (ptr == NULL)
	{
		*lst = new;
		return ;
	}
	ptr->next = new;
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *list = ft_lstnew("lorem");
// 	if (!list)
// 		return (0);
// 	t_list *elem = ft_lstnew("ipsum");
// 	if (!elem)
// 		return (0);
// 	printf("%p\n", list->next);
// 	ft_lstadd_back(&list, elem);
// 	printf("%p\n", list->next);
// 	return (0);
// }