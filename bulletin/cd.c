/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:40:28 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/19 02:31:13 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_get_cd(char *cmd)
{
    char **tab;

    tab = ft_split(cmd, ' ');
    return (tab[0]);
}

char *ft_get_home()
{
    char *home;

    home = getenv("HOME");
    return (home);
}


char *ft_get_path(char *cmd)
{
    int i;
    int j;
    char *path = NULL; 
    char **tab;

    i = 0;
    j = 0;
    path = (char *)malloc(sizeof(char) * ft_strlen(cmd));
    if (!path)
        return (NULL);
    tab = ft_split(cmd, ' ');    
    if (ft_strcmp(tab[0], "cd") == 0)
        ft_strcpy(path, tab[1]);
    // printf("%d\n", ft_strcmp(tab[1], ""));
    // else if (ft_strcmp(tab[1], "") == -1)
    return (path);
}

void    ft_cd(char *cmd)
{
    t_env *t;
    char **home;

    home = ft_split(cmd, ' ');
    t = NULL;
    if (!cmd)
        return ; 
    char *path = ft_get_path(cmd);
    // if (ft_strcmp(home[0], "cd") == 0)
    // {
    //     if (!home[1])
    //         chdir(ft_get_home(t));
    // }
    if (chdir(path) == 0)
        return;
    perror(ft_get_path(cmd));
}

// int main()
// {
//     t_env *t = NULL;
//     printf("[%s]\n", getenv("HOME"));
//     return (0);
// }