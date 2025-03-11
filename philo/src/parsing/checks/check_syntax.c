/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:58:01 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/11 11:46:54 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_syntax(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-')
			return (1);
		if (args[i][j] == '+' && ft_isdigit(args[i][j + 1]))
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
