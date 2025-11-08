/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:24 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/21 14:07:02 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*res_f;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		res_f = f(lst->content);
		new_elem = ft_lstnew((t_list *)res_f);
		if (!new_elem)
		{
			del(res_f);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (new_list)
			ft_lstadd_back(&new_list, new_elem);
		else
			new_list = new_elem;
		lst = lst->next;
	}
	return (new_list);
}
