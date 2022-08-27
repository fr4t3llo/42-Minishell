/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:10 by skasmi            #+#    #+#             */
/*   Updated: 2022/08/27 20:55:48 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <./libc.h>


// global variable ***
int var_global;

//libft function
size_t	ft_strlen(const char *str);

// typedef struct s_token
// {
//     int type;
//     char value;
//     s_token *next;
// }   t_token;

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}                   t_list;

#endif