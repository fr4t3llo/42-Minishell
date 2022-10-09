/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:56:16 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/09 22:18:07 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_unset_more_then_one(char **ptr)
{
    int i;

    i = 1;
    while (ptr[i])
    {
        ft_unset(ptr[i]);
        i++;
    }
}

void ft_unset(char *cmd)
{
    int     i;
    t_env   *tmp_prev;
    t_env   *tmp;

    i = 0;
    tmp = g_var.env;
    if (tmp->next)
    {
        tmp_prev = tmp;
               
    }
    while (tmp)
    {

        if (i = 0 && ft_strcmp(cmd, tmp->data) == 0)
        {
            g_var.env = g_var.env->next;
            break;
        }
        else if (tmp->next)
        {
            
            if(ft_strcmp(cmd, tmp->next->data) == 0)
            {
               
                tmp_prev = tmp->next;
                tmp_prev->next = tmp_prev;
                break;
            }
        }
        i = 1;
        tmp = tmp->next;
    }
}