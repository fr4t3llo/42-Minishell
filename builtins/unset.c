/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:56:16 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/06 21:10:49 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_unset(char *cmd)
{
    char    **splt;
    t_env   *tmp_next;
    t_env   *tmp_prev;
    int     i;
    t_env   *tmp;

    i = 1;
    tmp = g_var.env;
    splt = ft_split(cmd, ' ');
	// tmp = g_var.env;
    while (splt[i])
    {
        tmp = g_var.env;
        while (tmp)
        {
            if(ft_strcmp(splt[i], tmp->data) == 0)
            {
                if (tmp->prev == NULL)
                {
                    g_var.env = g_var.env->next;
                    if (!g_var.env)
                        g_var.env->prev = NULL;
                    break;
                }
                tmp_next = tmp->next;
                tmp_prev = tmp->prev;
                free(tmp->data);
                tmp_prev->next = tmp_next;
                break;
            }     
            tmp = tmp->next;
        }
        i++;
    }
}