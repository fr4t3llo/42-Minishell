/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:06:04 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/21 17:35:22 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token *ft_get_token(char *str)
{
    t_token *t;
    char    *token;
    int i;
    int j;

    j = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '|' || str[i] == '<')
        {
            token[j] = str[i];
            i++;
            j++;
        }   
        else   
    }
    return (t);
}