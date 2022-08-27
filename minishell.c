/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/08/27 20:35:42 by skasmi           ###   ########.fr       */
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

int main(int ac, char **av)
{
    int     i;
    // int     j;
    int     k;
    char    *str;
    // char    **splt;
    char    **tab;
    int     l;
    (void)ac;
    (void)av;

    
    i = 0;
    k = 0;
    l = 0;
    while (1)
    {
        str = readline("FRATELLO => ");
        tab = (char **)malloc(sizeof(char) * ft_strlen(str));
        if (!tab)
            return 0;
        // tab = ft_split(str, '|');
        // while (tab[i])
        // {
        //     printf ("%s\n", tab[i]);
        //     i++;
        // }
    }
    // while (str[i])
    // {
    //     if (str[i] >= 'a' && str[i] <= 'z')
    //     {
    //         tab[k][j] = str[i];
    //         j++;
    //         i++;
    //     }
    //     else if (str[i] == '>')
    //     {
    //         tab[k][j] = str[i];
    //         i++;
    //         j++;
    //     }
    //     else if (str[i] == '|')
    // }
    return (0);
}