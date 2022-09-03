/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/03 01:01:07 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ************************ create new list *********************************
t_list  *ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(*lst))))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

// ************************  check last node  ********************************
t_list  *ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

//************* add node to the last node in liked list ***********************
void    ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

// **************** copy string between n & m in new str **********************
char *ft_strnput(char *str, int n, int m)
{
    int i;
    int j;

    j = 0;
    i = 0;
    char *tab;
    tab = (char *)malloc(sizeof(char) * (n + m) + 1);
    while (n < m)
    {
        tab[j] = str[n];
        j++;
        n++;
    }
    tab[j] = '\0';
    return (tab);
}

// ********************* stock all env in table 2D called env_var *************
char    **copy_envs(char **env)
{   
    int nb_of_line = 0;
    int nb_for_alloc = 0;
    char **env_var;
    while (env[nb_of_line])
    {
        nb_for_alloc = strlen(env[nb_of_line]);
        env_var = (char **)malloc(sizeof(char) * nb_for_alloc);
        nb_of_line++;
        nb_for_alloc++;
    }
    nb_of_line = 0;
    nb_for_alloc = 0;
    while (env[nb_of_line])
    {
        env_var[nb_for_alloc] = env[nb_of_line];
        nb_for_alloc++;
        nb_of_line++;
    }
    return (env_var);
}

t_env *ft_new_env(char **env)
{
    t_env *new_env_list = NULL;
    char **splt;
    int i;
    
    i = 0;
    while (env[i])
    {
        splt = ft_split(env[i], '=');
        ft_lst_addback_env(&new_env_list, ft_lstnew_env(splt[0], splt[1]));
        i++;
        free(splt);
    }
    return (new_env_list);
}
int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    char *cmd;
    char **new_env;
    char **tab;
    t_env *list_env;

    new_env = copy_envs(env);
    list_env = ft_new_env(env);
    // printf("hello\n");
    while (1)
    {
        cmd = readline("FRATELLO😈=> ");
        // if(cmd[0] == 'e' && cmd[1] == 'n' && cmd[2] == 'v')
        if (ft_strcmp(cmd, "env") == 0)
            ft_env(list_env);
        add_history(cmd);
        tab = (char **)malloc(sizeof(char) * strlen(cmd));
        if (!tab)
            return 0;
        // printf("%s\n", cmd);
    }
    return (0);
}
