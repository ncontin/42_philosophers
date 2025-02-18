/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:57:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/18 13:07:18 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_empty(char **args)
{
	char	*trimmed_arg;
	int		i;

	i = 0;
	while (args[i])
	{
		trimmed_arg = ft_strtrim(args[i], " ");
		if (trimmed_arg[0] == '\0')
		{
			free(trimmed_arg);
			return (1);
		}
		free(trimmed_arg);
		i++;
	}
	return (0);
}
