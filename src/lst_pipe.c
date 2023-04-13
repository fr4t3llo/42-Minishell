/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:37:15 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:45:43 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back(t_pipe **lst, char *new)
{
	t_pipe	*lstptr;

	if (!*lst)
	{
		ft_lstadd_front(lst, ft_lstnew(new));
		return ;
	}
	lstptr = ft_lstlast(*lst);
	lstptr->next = ft_lstnew(new);
}

void	ft_lstadd_front(t_pipe **lst, t_pipe *new)
{
	new->next = *lst;
	*lst = new;
}

t_pipe	*ft_lstlast(t_pipe *lst)
{
	t_pipe	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (!ptr->next)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}

t_pipe	*ft_lstnew(char *content)
{
	t_pipe	*node;

	node = (t_pipe *)malloc(sizeof(t_pipe));
	if (!node)
		return (0);
	add_garbage(node);
	node->cmd = ft_extratct_string_from_qutes(ft_expand(content));
	node->next = 0;
	return (node);
}
