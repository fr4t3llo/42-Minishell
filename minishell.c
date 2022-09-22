/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/22 18:36:19 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// // ************************ create new list *********************************
// t_list  *ft_lstnew(void *content)
// {
// 	t_list	*lst;

// 	if (!(lst = (t_list*)malloc(sizeof(*lst))))
// 		return (NULL);
// 	lst->content = content;
// 	lst->next = NULL;
// 	return (lst);
// }

// // ************************  check last node  ********************************
// t_list  *ft_lstlast(t_list *lst)
// {
// 	while (lst)
// 	{
// 		if (!lst->next)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

// //************* add node to the last node in liked list ***********************
// void    ft_lstadd_back(t_list **alst, t_list *new)
// {
// 	t_list	*last;

// 	if (alst)
// 	{
// 		if (*alst)
// 		{
// 			last = ft_lstlast(*alst);
// 			last->next = new;
// 		}
// 		else
// 			*alst = new;
// 	}
// }

// // **************** copy string between n & m in new str **********************
// char *ft_strnput(char *str, int n, int m)
// {
//     int i;
//     int j;

//     j = 0;
//     i = 0;
//     char *tab;
//     tab = (char *)malloc(sizeof(char) * (n + m) + 1);
//     while (n < m)
//     {
//         tab[j] = str[n];
//         j++;
//         n++;
//     }
//     tab[j] = '\0';
//     return (tab);
// }

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

void    ft_bulletin(char *cmd, t_env *t)
{
    if (ft_syntax_general(cmd) == 0)
        printf("Minishell : syntax error !!\n");
    if (ft_strcmp(ft_execute_bulletin(cmd), "exit") == 0)
            ft_exit(cmd);
    if (ft_strcmp(ft_execute_bulletin(cmd), "pwd") == 0)
            ft_pwd(cmd);
    if (ft_strcmp(ft_execute_bulletin(cmd), "cd") == 0)
            ft_cd(cmd);
    if (ft_strcmp(ft_execute_bulletin(cmd), "env") == 0)
            ft_env(t);
}

void    handle_signal(int sig)
{
    (void)sig;
    // signal(SIGINT, NULL);
    printf("FRATELLO😈=>\n");
}


int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    char *cmd;
    // char **nothing = NULL;
    t_env *list_env;

    list_env = ft_new_env(env);
    struct sigaction sa;
    sa.sa_handler = &handle_signal;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);
    while (1)
    {
        cmd = readline("FRATELLO😈=> ");
        if (sigaction(SIGINT, &sa, NULL) == 1)
        {
            printf("wa hya sidi rebi\n");
            continue;
        }
        ft_expand(cmd);
        // nothing = ft_split(cmd, ' ');
        // if (ft_strcmp(nothing[0], "") == 0)
        //     continue;
        if (!cmd)
            break ; // free allocated memory
            // printf("{%s}\n", nothing[0]);
        if (cmd[0] == '\0') {
            free(cmd);
            continue;
        }
        ft_bulletin(cmd, list_env);
        // if (ft_strcmp(cmd, "export") == 0)
        //     ft_export(list_env);
        add_history(cmd);
    }
    return (0);
}
