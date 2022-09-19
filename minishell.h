/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:10 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/19 01:59:58 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <./libc.h>

# define pipe
# define word
# define red
# define dbl_qt
# define sngl_qt

// global variable ***
int var_global;

//libft function
int	ft_strlen(const char *str);

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

// int	ft_check_parenthese(char *cmd);
int	ft_check_cmd_sq_q(char *cmd);
int ft_check_pipe(char *cmd);
int ft_check_redirection(char *cmd);
int ft_skip_before_space(char *cmd);
int	ft_check_semicolon(char *cmd);
int ft_syntax_general(char *cmd);

// Expend
int ft_expand(char *cmd);

//libft_funcs
char	**ft_split(char const *s, char c);
int ft_strcmp(char *s1, char *s2);
char    *ft_strcpy(char * dst, const char * src);
int	ft_atoi(const char *str);

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
char    *ft_execute_bulletin(char *cmd);
void    ft_pwd();
void    ft_export(t_env *t);
void    ft_cd(char *path);
char *ft_get_home(t_env *t);
int   	ft_exit(char *cmd);
char	*ft_get_cd(char *cmd);

#endif