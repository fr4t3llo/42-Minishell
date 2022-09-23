/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:23:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/23 01:25:43 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char buff[1024];

// if ((getcwd(buff, sizeof(buff))) == NULL)
//     printf("Erroooor\n");
// else 
void	ft_pwd(int c)
{
	(void)c;
	printf("%s\n", getcwd(NULL, 0));
}
