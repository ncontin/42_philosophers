/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:40 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/25 18:44:26 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->table->start_time = get_time();
	if (philo->philo_id % 2 == 0)
		ft_usleep(10);
	// THINK
	// printf("Philosopher %d is thinking\n", philo->philo_id);
	// TAKE FORKS
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
		pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
		printf("%ld Philosopher %d has taken and locked fork right n: %d\n",
			get_time() - philo->table->start_time, philo->philo_id,
			philo->fork_right);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
		printf("%ld Philosopher %d has taken and locked fork left n: %d\n",
			get_time() - philo->table->start_time, philo->philo_id,
			philo->fork_right);
		pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
		printf("%ld Philosopher %d has taken and locked fork right n: %d\n",
			get_time() - philo->table->start_time, philo->philo_id,
			philo->fork_left);
	}
	// EAT
	printf("%ld Philosopher %d is eating\n", get_time()
		- philo->table->start_time, philo->philo_id);
	ft_usleep(philo->table->tt_eat);
	// PUT DOWN FORKS
	pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
	printf("%ld Philosopher %d has put down and unlocked fork left n: %d\n",
		get_time() - philo->table->start_time, philo->philo_id,
		philo->fork_left);
	pthread_mutex_unlock(&philo->table->forks[philo->fork_right]);
	printf("%ld Philosopher %d has put down and unlocked fork right n: %d\n",
		get_time() - philo->table->start_time, philo->philo_id,
		philo->fork_right);
	// SLEEP
	printf("%ld Philosopher %d is sleeping\n", get_time()
		- philo->table->start_time, philo->philo_id);
	ft_usleep(philo->table->tt_sleep);
	printf("Philosopher %d is thinking\n", philo->philo_id);
	// check_dead or limit reached
	return (NULL);
}

// void	monitor_routine(void)
// {
// }
