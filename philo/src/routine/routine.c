/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:40 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/04 17:49:11 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		ft_usleep(50);
	while (1)
	{
		pthread_mutex_lock(&philo->table->table_lock);
		if (philo->table->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->table->table_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->table_lock);
		if (philo->table->philos_nbr == 1)
		{
			pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
			pthread_mutex_lock(&philo->table->print_mutex);
			printf("%ld %d has taken a fork\n", get_time()
				- philo->table->start_time, philo->philo_id);
			pthread_mutex_unlock(&philo->table->print_mutex);
			// Wait until the philosopher dies (since they can't eat with only one fork)
			ft_usleep(philo->table->tt_die);
			pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
			return (NULL);
		}
		pthread_mutex_lock(&philo->table->table_lock);
		if (philo->table->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->table->table_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->table_lock);
		if (is_full(philo) == 1)
			break ;
		philo_take_forks(philo);
		pthread_mutex_lock(&philo->table->table_lock);
		if (philo->table->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->table->table_lock);
			philo_drop_forks(philo);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->table_lock);
		philo_eat(philo);
		pthread_mutex_lock(&philo->table->table_lock);
		if (philo->table->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->table->table_lock);
			philo_drop_forks(philo);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->table_lock);
		philo_drop_forks(philo);
		pthread_mutex_lock(&philo->table->table_lock);
		if (philo->table->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->table->table_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->table_lock);
		philo_sleep(philo);
		pthread_mutex_lock(&philo->table->table_lock);
		if (philo->table->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->table->table_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->table_lock);
		philo_think(philo);
		pthread_mutex_lock(&philo->table->table_lock);
		if (philo->table->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->table->table_lock);
			philo_drop_forks(philo);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->table_lock);
	}
	return (NULL);
}
