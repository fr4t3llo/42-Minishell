/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_general.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:43:46 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/12 16:49:22 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_syntax_general(char *cmd)
{
	if (ft_check_red(cmd) == 1)
		return (1);
	if (ft_check_pipe(cmd) == 1)
		return (1);
	if (ft_check_before_after_symbole(cmd) == 1)
		return (1);
	if (ft_check_single_dbl_qt(cmd) == 1)
		return (1);
	return (0);
}
