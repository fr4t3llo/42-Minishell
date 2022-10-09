/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:23:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/09 12:12:37 by matef            ###   ########.fr       */
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
	char	s[1024];

	printf("%s\n", getcwd(s, 1024));
}
