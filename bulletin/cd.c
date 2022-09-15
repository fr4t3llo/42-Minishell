/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:40:28 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/15 04:41:46 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char *ft_skip_space(char *string, int n)
// {
//     int i;
//     int j;

//     j = 0;
//     i = 0;
//     char *without_space;
//     without_space = (char *)malloc(sizeof(char *) * ft_strlen(string));
//     while (string[i] && string[i] == ' ')
//         i++;
//     while(string[i] && string[i] != ' ')
//     {
//         without_space[j] = string[i];
//         i++;
//         j++;
//     }
//     return (without_space);
// }

char *ft_get_cd(char *cmd)
{
    char **tab;

    tab = ft_split(cmd, ' ');
    return (tab[0]);
}

char *ft_get_path(char *cmd)
{
    int i;
    int j;
    char *path;
    char **tab;

    i = 0;
    j = 0;
    path = (char *)malloc(sizeof(char) * ft_strlen(cmd));
    tab = ft_split(cmd, ' ');    
    if (ft_strcmp(tab[0], "cd") == 0)
        ft_strcpy(path, tab[1]);
    return (path);
}

void    ft_cd(char *cmd)
{
    // printf("im here \n");     
    char *path = ft_get_path(cmd);
    if (chdir(path) == 0)
        return;
        // perror(ft_get_path(cmd));
        
}
// int main()
// {
//    char *str = "            cd              Desktop/minishell            ";
// //    char *path = ft_get_path(str);
//     ft_get_cd(str);
// //    printf("%s\n", path);
//    return (0); 
// }