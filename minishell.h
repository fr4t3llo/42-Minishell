/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:10 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/07 02:06:56 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
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
// }   t_token

typedef struct s_env
{
	char *data;
	char *value;
	struct s_env *next;
	struct s_env *prev;
}	t_env;


typedef struct s_int
{
	int i;
	int j;
	int k;
	int nb_for_alloc;
	int nb_of_line;
}		t_int;


typedef	struct	s_list
{
	char			*content;
	struct s_list	*next;
}                   t_list;
//syntax error **********************************

int	ft_check_parenthese(char *cmd);
int	ft_check_cmd_sq_q(char *cmd);

//libft_funcs
char	**ft_split(char const *s, char c);
int ft_strcmp(char *s1, char *s2);

//list env

t_env  *ft_lstnew_env(char *data, char *value);
void	ft_lst_addback_env(t_env **lst, t_env *new);
t_env	*ft_lstlast_env(t_env *lst);
//lists
t_list  *ft_lstnew(void *content);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **alst, t_list *new);

//minishell function 

void	ft_env(t_env *t);
void    ft_pwd();

#endif