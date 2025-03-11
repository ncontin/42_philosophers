/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:57:48 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/11 11:46:54 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_overflow(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}
