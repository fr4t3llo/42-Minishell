/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:23:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/08/23 15:51:20 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main()
{
    // char buff[1024];
    
    // if ((getcwd(buff, sizeof(buff))) == NULL)
    //     printf("Erroooor\n");
    // else 
        printf("the direcoty is : \033[0;33m%s\n", getcwd(NULL, 0));
    return (0);
}