/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:55:51 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/06 22:53:41 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_value(char *cmd)
{
	int 	i;
	int 	j;
	char	*value = NULL;

	j = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '=')
		{
			while (cmd[i])
			{
				i++;
				j++;
			}
		}
		i++;
	}
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '=')
		{
			value = ft_substr(cmd, ++i, j);
			break;
		}
		i++;
	}
	return (ft_strdup(value));
}

void *ft_get_data(char *cmd)
{
	int i;
	int j;
	char str[9999];
	
	i = 0;
	j = 0;
	while (cmd[i] != '=' && cmd[i])
	{
		str[j] = cmd[i];
		i++;
		j++; 		
	}
	str[j] = '\0';
	return (ft_strdup(str));
}

void	ft_export(char *cmd)
{
    t_env	*tmp;
    int		i;
    char	**splt;
	char	*value;
	char	*data;

	i = 0;
	tmp = g_var.env;
    splt = ft_split(cmd, ' ');
	if (!splt)
		return ;
	data = ft_get_data(splt[1]);
	value = ft_get_value(splt[1]);
	t_env *new = (t_env*)malloc(sizeof(t_env));
	new->data = data;
	new->value = value;
	new->next = NULL;
	while (tmp) 
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
}

// int main()
// {
// 	char *str = "user============ftsplit";
// 	printf("%s\n", ft_get_value(str));
// }
