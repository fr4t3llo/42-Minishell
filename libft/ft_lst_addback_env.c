/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:06:57 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/23 01:30:21 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lst_addback_env(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (*lst)
	{
		tmp = ft_lstlast_env(*lst);
		tmp->next = new;
		new->prev = tmp;
	}
	else
		*lst = new;
}
