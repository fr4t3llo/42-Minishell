/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:56:01 by matef             #+#    #+#             */
/*   Updated: 2022/10/22 05:45:45 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	open_to_write(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error fd\n", 2);
		return ;
	}
	dup2(fd, 1);
	close(fd);
}

void	open_to_read(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error fd\n", 2);
		return ;
	}
	dup2(fd, 0);
	close(fd);
}

void	open_to_append(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error fd\n", 2);
		return ;
	}
	dup2(fd, 1);
	close(fd);
}

void	run_rediction(t_redic *lst_of_red)
{
	t_redic	*tmp_r;

	tmp_r = lst_of_red;
	while (tmp_r)
	{
		if (tmp_r->type == RED_OUT)
			open_to_write(tmp_r->content);
		else if (tmp_r->type == RED_IN)
			open_to_read(tmp_r->content);
		else if (tmp_r->type == APPEND)
			open_to_append(tmp_r->content);
		tmp_r = tmp_r->next;
	}
}
