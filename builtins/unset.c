/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:56:16 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/12 16:50:53 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset_more_then_one(char **ptr)
{
	int	i;

	i = 1;
	while (ptr[i])
	{
		ft_unset(ptr[i]);
		i++;
	}
}

/*
void	ft_unset(char *cmd)
{
    t_env   *tmp_prev;
    t_env   *tmp;

    tmp = g_var.env;
    if (tmp->next)
    {
        tmp_prev = tmp;
    }
    while (tmp)
    {
        if (ft_strcmp(cmd, tmp->data) == 0)
        {
            g_var.env = g_var.env->next;
            break ;
        }
        else if (tmp->next)
        {
            
            if(ft_strcmp(cmd, tmp->next->data) == 0)
            {
               
                tmp_prev = tmp->next;
                tmp_prev->next = tmp_prev;
                break ;
            }
        }
        tmp = tmp->next;
    }
}
*/

void	ft_unset(char *cmd)
{
	t_env *tmp_next;
	t_env *tmp_prev;
	t_env *tmp;

	tmp = g_var.env;
	if (tmp && tmp->next == NULL && tmp->prev == NULL)
	{
		if (ft_strcmp(cmd, tmp->data) == 0)
			g_var.env = NULL;
		return ;
	}

	while (tmp)
	{
		tmp_next = tmp->next;
		tmp_prev = tmp->prev;
		if (ft_strcmp(cmd, tmp->data) == 0)
		{
			// free current node
			if (tmp_prev)
			{
				tmp_prev->next = tmp_next;
				if (tmp_next)
					tmp_next->prev = tmp_prev;
			}
			else
			{
				g_var.env = tmp_next;
				if (tmp_next)
					tmp_next->prev = NULL;
			}
			break ;
		}
		tmp = tmp_next;
	}
}