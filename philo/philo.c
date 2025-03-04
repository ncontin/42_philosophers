/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/04 17:31:44 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_philos(void *arg)
{
	t_table	*table;
	int		i;
	long	interval;
	int		full_count;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		full_count = 0;
		while (i < table->philos_nbr)
		{
			pthread_mutex_lock(&table->philos[i].philo_lock);
			interval = get_time() - table->philos[i].last_meal_time;
			if (interval > table->tt_die)
			{
				pthread_mutex_lock(&table->table_lock);
				table->someone_died = 1;
				pthread_mutex_unlock(&table->table_lock);
				pthread_mutex_lock(&table->print_mutex);
				printf("%ld %d died\n", get_time() - table->start_time,
					table->philos[i].philo_id);
				pthread_mutex_unlock(&table->print_mutex);
				pthread_mutex_unlock(&table->philos[i].philo_lock);
				return (NULL);
			}
			if (table->philos[i].meals_eaten >= table->meals_per_philo)
				full_count++;
			pthread_mutex_unlock(&table->philos[i].philo_lock);
			i++;
		}
		if (full_count == table->philos_nbr && table->meals_per_philo > 0)
		{
			pthread_mutex_lock(&table->table_lock);
			table->end_dinner = 1;
			pthread_mutex_unlock(&table->table_lock);
			return (NULL);
		}
		usleep(50);
	}
	return (NULL);
}

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
