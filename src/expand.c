/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 04:45:00 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/03 01:00:42 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_expand(char *cmd)
{
    int     i;
    char    *ptr;

    i = 0;
    ptr = ft_strdup("");
    if (cmd[0] == '~')
    {
        if (cmd[1] == '/' || cmd[1] == ' ' || cmd[1] == '\0')
        {
            ptr = ft_strjoin(ptr, getenv("HOME"));
            if (cmd[1])
                i++;
            i++;
        }
    }
    while (cmd[i])
    {


        if (cmd[i] == '$')

        if (cmd[i] == '$' && cmd[i + 1] == '?')
        {
            printf("this is expend !!!\n");
            return (0);
        }
        i++;
    }
    return (0);
}