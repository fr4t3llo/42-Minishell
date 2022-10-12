/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:23:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/12 16:51:22 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char buff[1024];

// if ((getcwd(buff, sizeof(buff))) == NULL)
//     printf("Erroooor\n");
// else
void	ft_pwd(int c)
{
	char	s[1024];

	(void)c;
	printf("%s\n", getcwd(s, 1024));
}
