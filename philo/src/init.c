/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:41:14 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/26 12:34:38 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	init_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->philos_nbr);
	if (!table->philos)
		return (1);
	i = 0;
	while (i < table->philos_nbr)
	{
		table->philos[i].philo_id = i + 1;
		table->philos[i].fork_right = i;
		table->philos[i].fork_left = (i + 1) % table->philos_nbr;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal_time = 0;
		table->philos[i].table = table;
		pthread_mutex_init(&(table->philos[i].meal_lock), NULL);
		i++;
	}
	return (0);
}

static int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philos_nbr);
	if (!table->forks)
		return (1);
	while (i < table->philos_nbr)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			while (i > 0)
				pthread_mutex_destroy(&table->forks[i--]);
			free(table->forks);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	init_table(t_table *table)
{
	table->start_time = 0;
	table->end_dinner = 0;
	init_forks(table);
	return (0);
}

int	init_data(t_table *table)
{
	if (init_table(table) == 1 || init_philos(table) == 1)
		return (1);
	return (0);
}
