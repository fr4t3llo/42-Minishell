/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:00:12 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/05 02:24:14 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_cmd_sq_q(char *cmd)
{
	int i;
	char quote;
	
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			quote = cmd[i];
			i++;
			while (cmd[i] != quote)
			{
				if (cmd[i] == '\0')
					return (0);
				i++;
			}
		}
		i++;
	}
	return (1);
}	

int main()
{
	char *cmd = "ls -la \" ls \" | \'\' ";
	
	printf("%d\n", ft_check_cmd_sq_q(cmd));
}