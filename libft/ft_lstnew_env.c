/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:02:49 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/23 01:31:47 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstnew_env(char *data, char *value)
{
	t_env	*t;

	t = (t_env *)malloc(sizeof(t_env));
	if (!t)
		return (0);
	t->data = data;
	t->value = value;
	t->next = NULL;
	t->prev = NULL;
	return (t);
}
