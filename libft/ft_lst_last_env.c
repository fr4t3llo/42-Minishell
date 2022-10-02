/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:10:11 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/23 01:31:21 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	lst = lst->next;
	return (lst);
}
