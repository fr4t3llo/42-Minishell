/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:10 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/26 22:40:00 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <./libc.h>

# define PIPE 1
# define WORD 2
# define RED_IN 3
# define RED_OUT 4
# define DBL 5
# define SNGL 6
# define HEREDOC 7
// global variable ***

typedef struct s_env
{
	char			*data;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef	struct	s_global_var
{
	t_env	*env;
} t_global_var;

t_global_var g_var;

//libft function
int	ft_strlen(const char *str);

typedef struct s_token
{
	int				type;
	char			value;
	struct s_token	*next;
}	t_token;


typedef struct s_int
{
	int	i;
	int	j;
	int	k;
	int	nb_for_alloc;
	int	nb_of_line;
}		t_int;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_pipe
{
	char	*cmd;
	struct s_pipe *next;
}	t_pipe;

//syntax error **********************************

// int	ft_check_parenthese(char *cmd);

int	ft_check_pipe(char *cmd);
int	ft_check_red(char *cmd);
void skip_single_dbl_quote(char *line, int *k);
int	ft_check_cmd_sq_q(char *cmd);
int	ft_check_dbl_pipe(char *cmd);
int	ft_check_redirection(char *cmd);
int	ft_check_redirection_2(char *cmd);
int	ft_skip_before_space(char *cmd);
int	ft_check_semicolon(char *cmd);
int	ft_syntax_general(char *cmd);
int	ft_get_before(char	*line, int index);
int	ft_get_after(char *line, int index);
int	ft_check_before_after_symbole(char *cmd);
int	ft_check_single_dbl_qt(char *cmd);
int	ft_complete(char *cmd, int i);
int	ft_check_single_dbl_qt(char *cmd);
// Expend
int	ft_expand(char *cmd);

//libft_funcs
char	**ft_split(char const *s, char c);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

//list env
t_env	*ft_lstnew_env(char *data, char *value);
void	ft_lst_addback_env(t_env **lst, t_env *new);
t_env	*ft_lstlast_env(t_env *lst);
//lists
/*
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
*/
//minishell function
void		ft_env(t_env *t);
char		*ft_execute_bulletin(char *cmd);
void		ft_pwd();
void		ft_export(t_env *t);
void		ft_cd(char *path);
char		*ft_get_home(t_env *t);
int			ft_exit(char *cmd);
char		*ft_get_cd(char *cmd);
void		ft_pipe(char *cmd);
int	ft_bulletin(char *cmd, t_env *t);


// list of pipes

void		ft_lstadd_back(t_pipe **lst, char *new);
void		ft_lstadd_front(t_pipe **lst, t_pipe *new);
t_pipe		*ft_lstlast(t_pipe *lst);
t_pipe		*ft_lstnew(char *content);

void   		ft_start_exe(t_pipe *lst);
void   		ft_execution(char   *cmd);
char		**ft_get_env2(void);

#endif
