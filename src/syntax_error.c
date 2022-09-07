/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:00:12 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/07 02:11:54 by skasmi           ###   ########.fr       */
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

int	ft_check_parenthese(char *cmd)
{
		int i;
		int parent;
		
		i = 0;
		parent = 0;
		if (ft_check_cmd_sq_q(cmd) == 1)
		{
			while (cmd[i])
			{
				if (cmd[i] == '(')
					parent++;
				else if (cmd[i] == ')' && parent > 0)
					parent--;
				else if (cmd[i] == ')' && parent == 0)
					return (0);
				i++;
			}
		}
		if (parent != 0)
			return (0);
	return (1);
}
// #include <stdio.h>

// int main()
// {
// 	char *str = "ld -la () () (()))";
// 	printf("%d\n", ft_check_parenthese(str));
// 	// printf("%d\n", check_parent(str));
// 	return (0);
// }