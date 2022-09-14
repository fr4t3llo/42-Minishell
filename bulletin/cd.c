/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:40:28 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/14 23:14:10 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_skip_space(char *string, int n)
{
    int i;
    int j;

    j = 0;
    i = 0;
    char *without_space;
    without_space = (char *)malloc(sizeof(char *) * ft_strlen(string));
    while (string[i] && string[i] == ' ')
        i++;
    while(string[i] && string[i] != ' ')
    {
        without_space[j] = string[i];
        i++;
        j++;
    }
    return (without_space);
}

char *ft_get_path(char *cmd)
{
    int i;
    int j;
    char *path;
    
    i = 0;
    j = 0;
    path = (char *)malloc(sizeof(char) * ft_strlen(cmd));
    while (cmd[i])
    {
        if (cmd[i] == 'c' && cmd[i + 1] == 'd')
        {
            i += 2;
            path = ft_skip_space(cmd);
        }
        else 
            i++;
    }
    return (path);
}


int main()
{
   char *str = "cd Desktop";
   char *path = ft_get_path(str);
   printf("%s\n", path);
   return (0); 
}

// int chdir(const char *path) // return 0 if change directory success || -1 if error ...
// {
    
// }
// int main()
// {
//     int i = chdir("/Users/skasmi/Desktop");
//     if(i < 0)
//         printf("not change directory .. \n");
//     else
//         printf("change success\n");
//     return(0);
// }
