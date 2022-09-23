/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:00:12 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/23 23:04:31 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_single_dbl_qt(char *cmd)
{
	int		i;
	char	quote;

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

// int	ft_check_semicolon(char *cmd)
// {
// 	int i;

// 	i = 0;
// 	if (ft_check_cmd_sq_q(cmd) == 1)
// 	{
// 		while (cmd[i])
// 		{
// 			if (cmd[i] == '\\' || cmd[i] == ';' || cmd[i] == ':')
// 				return (0);
// 			i++;
// 		}
// 	}
// 	return (1);
// }

// int	ft_check_redirection_2(char *cmd)
// {
// 	int i;

// 	i = 0;
// 	if (ft_check_cmd_sq_q(cmd) == 1)
// 	{
// 		while (cmd[i])
// 		{
// 			if (cmd[i] == '>')
// 			{
// 				printf("%c\n", cmd[i]);
// 				while (cmd[i] || cmd[i] == ' ')
// 				{
// 					if (cmd[i] == '<')
// 						return (0);
// 					i++;
// 				}
// 			}
// 			i++;				
// 			// if (cmd[i] == '>' && cmd[i + 1] == '<')
// 			// 	return (0);
// 			// else if (cmd[i] == '<' && cmd[i + 1] == '>')
// 			// 	return (0);
// 			// i++	
// 		}
// 	}
// 	return (1);
// }

int	ft_check_pipe(char *cmd)
{
	int		i;
	int		k;
	char	**splt;

	splt = ft_split(cmd, ' ');
	i = 0;
	k = 0;
	while (splt[k])
		k++;
	if (!splt[0])
		return (2);
	if (ft_check_single_dbl_qt(cmd) == 1)
	{
		if (ft_strcmp(splt[0], "|") == 0)
			return (0);
		else if (ft_strcmp(splt[k - 1], "|") == 0)
			return (0);
	}
	return (1);
}

int	ft_check_dbl_pipe(char *cmd)
{
	int	i;

	i = 0;
	if (ft_check_single_dbl_qt(cmd) == 1)
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
	if (ft_check_single_dbl_qt(cmd) == 1)
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

int	ft_check_red(char *cmd)
{
	int		i;
	int		x;
	char	**tab;

	i = 0;
	tab = ft_split(cmd, ' ');
	if (ft_check_single_dbl_qt(cmd) == 1)
	{
		if (!tab[i])
			return (1);
		while (tab[i])
			i++;
		i--;
		x = ft_strlen(tab[i]) - 1;
		if (!tab[i][x])
			return (0);
		if (ft_strcmp(&tab[i][x], "<") == 0 || ft_strcmp(&tab[i][x], ">") == 0)
			return (0);
	}
	return (1);
}

int ft_get_before(char *line ,int index)
{
    int i;
	
    i = index;
	i--;
    while(i)
    {
        if(line[i] != ' ')
            return i;
        i--;
    }
    return (index - 1);
}

int ft_get_after(char *line ,int index)
{
    int i;
	
    i = index;
	i++;
    while(line[i])
    {
        if(line[i] != ' ')
            return i;
        i++;
    }
    return (index + 1) ;
}
void skip_single_dbl_quote(char *line , int *k)
{
    int i;
    char c;

    i = *k;
    if(line[i] == '\"' || line[i] == '\'')
        {
            c = line[i];
            i++;
            while ( line[i] != c && line[i] != '\0')
                i++;
        }
    *k = i; 
}

int ft_check_before_after_symbole(char *cmd)
{
	int i;
	
	i = 0;
	while (cmd[i])
	{
		skip_single_dbl_quote(cmd, &i);
		if(cmd[i] == '|')
		{
			if(ft_strchr("|><" , cmd[ft_get_after(cmd,i)]) == 1)
				return(0);
			if(ft_strchr("|<>" , cmd[ft_get_before(cmd,i)]) == 1)
				return(0);
		}
		if(cmd[i] == '<' && cmd[i + 1] != '<' && cmd[i - 1] != '<')
		{
			if(ft_strchr("|<>" , cmd[ft_get_after(cmd,i)])== 1)
				return(0);
			if(ft_strchr("|<>" , cmd[ft_get_before(cmd,i)])== 1)
				return(0);
		}
		if(cmd[i] == '>' && cmd[i + 1] != '>' && cmd[i - 1] != '>')
		{
			if(ft_strchr("|<>" , cmd[ft_get_after(cmd,i)])== 1)
				return(0);
			if(ft_strchr("|<>" , cmd[ft_get_before(cmd,i)])== 1)
				return(0);
		}
		i++;
	}
	return(1);
	
}

int	ft_syntax_general(char *cmd)
{
	if (ft_check_before_after_symbole(cmd) == 0)
		return(0);
	if (ft_check_single_dbl_qt(cmd) == 0  || ft_check_pipe(cmd) == 0)
		return (0);
	else if (ft_check_redirection(cmd) == 0 || ft_check_red(cmd) == 0)
		return (0);
	else
		return (1);
}
