/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:49:32 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/07 17:16:55 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_death(t_table *table)
{
	int		i;
	long	interval;

	i = 0;
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
			if (table->philos[i].is_full != 1)
				printf("%ld %d died\n", get_time() - table->start_time,
					table->philos[i].philo_id);
			pthread_mutex_unlock(&table->print_mutex);
			pthread_mutex_unlock(&table->philos[i].philo_lock);
			return (1);
		}
		pthread_mutex_unlock(&table->philos[i].philo_lock);
		i++;
	}
	return (0);
}

static int	check_full_count(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
	{
		pthread_mutex_lock(&table->philos[i].philo_lock);
		if (table->philos[i].meals_eaten >= table->meals_per_philo)
			table->full_count++;
		pthread_mutex_unlock(&table->philos[i].philo_lock);
		i++;
	}
	if (table->full_count == table->philos_nbr && table->meals_per_philo > 0)
	{
		pthread_mutex_lock(&table->table_lock);
		table->end_dinner = 1;
		pthread_mutex_unlock(&table->table_lock);
		return (1);
	}
	return (0);
}

void	*monitor_philos(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (check_death(table) == 1)
			return (NULL);
		if (check_full_count(table) == 1)
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
