/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:56:41 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/04 16:22:48 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	is_philo_even(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
		pthread_mutex_unlock(&philo->table->print_mutex);
		pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
}

void	is_philo_odd(t_philo *philo)
{
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
		pthread_mutex_unlock(&philo->table->print_mutex);
		pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
}

void	philo_take_forks(t_philo *philo)
{
	is_philo_even(philo);
	is_philo_odd(philo);
}

void	philo_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork_right]);
}
