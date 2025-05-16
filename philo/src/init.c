/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:41:14 by ncontin           #+#    #+#             */
/*   Updated: 2025/05/12 12:32:05 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		table->philos[i].last_meal_time = get_time();
		table->philos[i].is_full = 0;
		table->philos[i].fork_left_flag = 0;
		table->philos[i].fork_right_flag = 0;
		table->philos[i].table = table;
		if (pthread_mutex_init(&table->philos[i].philo_lock, NULL) != 0)
			return (1);
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
				pthread_mutex_destroy(&table->forks[--i]);
			free(table->forks);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	init_table(t_table *table)
{
	table->start_time = get_time();
	table->someone_died = 0;
	table->full_count = 0;
	if (pthread_mutex_init(&(table->print_mutex), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(table->table_lock), NULL) != 0)
		return (1);
	if (init_forks(table) != 0)
		return (1);
	return (0);
}

int	init_data(t_table *table)
{
	if (init_table(table) == 1 || init_philos(table) == 1)
		return (1);
	return (0);
}
