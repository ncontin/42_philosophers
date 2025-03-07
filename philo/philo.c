/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/07 16:51:55 by ncontin          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_table	table;

	if (parse_args(argv, argc, &table) == 1)
		return (1);
	if (init_data(&table) == 1)
		return (1);
	if (create_threads(&table) == 1)
		return (1);
	if (join_threads(&table) == 1)
		return (1);
	if (cleanup(&table) == 1)
		return (1);
	return (0);
}
