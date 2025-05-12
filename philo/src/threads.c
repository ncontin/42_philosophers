/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:49:36 by ncontin           #+#    #+#             */
/*   Updated: 2025/05/12 11:50:17 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &start_routine,
				&table->philos[i]) != 0)
		{
			free_all(table);
			return (1);
		}
		i++;
	}
	if (pthread_create(&table->monitor, NULL, monitor_philos, table) != 0)
	{
		free_all(table);
		return (1);
	}
	return (0);
}

int	join_threads(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_join(table->monitor, NULL) != 0)
	{
		free_all(table);
		return (1);
	}
	while (i < table->philos_nbr)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
		{
			free_all(table);
			return (1);
		}
		i++;
	}
	return (0);
}
