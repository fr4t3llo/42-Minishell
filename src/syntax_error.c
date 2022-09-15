/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:00:12 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/15 17:48:24 by skasmi           ###   ########.fr       */
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

int ft_check_pipe(char *cmd)
{
	int i;
	// int pipe;
	
	i = 0;
	if (ft_check_cmd_sq_q(cmd) == 1)
	{
		while (cmd[i])
		{
			if (cmd[i] == '|' && cmd[i + 1] == '|')
				return (0);
			i++;
		}
	}
	return (1);
}

int ft_check_redirection(char *cmd)
{
	int i;

	i = 0;
	if (ft_check_cmd_sq_q(cmd) == 1)
	{
		while (cmd[i])
		{
			if (cmd[i] == '>' && cmd[i + 1] == '>' && cmd[i + 2] == '>')
				return (0);
			else if (cmd[i] == '<' && cmd[i + 1] == '<' && cmd[i + 2] == '<')
				return (0);
			i++;
		}
	}
	return (1);
}

// int ft_nothing(char *cmd)
// {
// 	int i;

// 	i = 0;
	
// }
int ft_syntax_general(char *cmd)
{
	if (ft_check_cmd_sq_q(cmd) == 0 || ft_check_pipe(cmd) == 0 || ft_check_redirection(cmd) == 0)
		return (0);
	else 
		return (1);
}

// int ft_skip_before_space(char *cmd)
// {
// 	int i;
// 	char **splt;
	
// 	i = 1;
// 	splt = ft_split(cmd, ' ');
// 	while (splt[i])
// 		i++;
// 	i--;
// 	// printf("%d\n", i);
// 	printf("[%c]\n", splt[1][0]);
// 	if (splt[i][0] == '|')
// 		return (0);
// 	// printf("im here\n");
// 	return (1);
// }
// int	ft_check_parenthese(char *cmd)
// {
// 		int i;
// 		int parent;
		
// 		i = 0;
// 		parent = 0;
// 		if (ft_check_cmd_sq_q(cmd) == 1)
// 		{
// 			while (cmd[i])
// 			{
// 				if (cmd[i] == '(')
// 					parent++;
// 				else if (cmd[i] == ')' && parent > 0)
// 					parent--;
// 				else if (cmd[i] == ')' && parent == 0)
// 					return (0);
// 				i++;
// 			}
// 		}
// 		if (parent != 0)
// 			return (0);
// 	return (1);
// }
// #include <stdio.h>


// int main()
// {
// 	char *str = "ld -la () () (())) |        ";
// 	printf("%d\n", ft_skip_before_space(str));
// 	// printf("%d\n", check_parent(str));
// 	return (0);
// }