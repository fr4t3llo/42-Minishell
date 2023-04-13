/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:56:05 by matef             #+#    #+#             */
/*   Updated: 2022/10/22 05:45:47 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back_red(t_redic **lst, char *new, char c)
{
	t_redic	*lstptr;

	if (!*lst)
	{
		ft_lstadd_front_red(lst, ft_lstnew_red(new, c));
		return ;
	}
	lstptr = ft_lstlast_red(*lst);
	lstptr->next = ft_lstnew_red(new, c);
}

void	ft_lstadd_front_red(t_redic **lst, t_redic *new)
{
	new->next = *lst;
	*lst = new;
}

t_redic	*ft_lstlast_red(t_redic *lst)
{
	t_redic	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (!ptr->next)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}

int	get_type_of_red(char c)
{
	if (c == '>')
		return (RED_OUT);
	else if (c == '<')
		return (RED_IN);
	return (APPEND);
}

t_redic	*ft_lstnew_red(char *content, char c)
{
	t_redic	*node;

	node = (t_redic *)malloc(sizeof(t_redic));
	if (!node)
		return (0);
	add_garbage(node);
	node->type = get_type_of_red(c);
	node->content = ft_expand(content);
	node->next = 0;
	return (node);
}
