/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:40:59 by ncontin           #+#    #+#             */
/*   Updated: 2025/05/12 12:30:21 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
	{
		if (pthread_mutex_destroy(&table->forks[i]) != 0)
			return (1);
		if (pthread_mutex_destroy(&table->philos[i].philo_lock) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&table->print_mutex) != 0)
		return (1);
	if (pthread_mutex_destroy(&table->table_lock) != 0)
		return (1);
	return (0);
}
