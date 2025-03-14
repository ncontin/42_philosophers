/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:56:41 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/14 17:37:17 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork_taken(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (!philo->table->someone_died)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	pthread_mutex_unlock(&philo->table->table_lock);
}

static void	even_take_forks(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
	print_fork_taken(philo);
	philo->fork_left_flag = 1;
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
	philo->fork_right_flag = 1;
	print_fork_taken(philo);
}

static void	odd_take_forks(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
	philo->fork_right_flag = 1;
	print_fork_taken(philo);
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
	philo->fork_left_flag = 1;
	print_fork_taken(philo);
}

void	philo_take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->forks_lock);
		odd_take_forks(philo);
		pthread_mutex_unlock(&philo->forks_lock);
	}
	else
	{
		pthread_mutex_lock(&philo->forks_lock);
		even_take_forks(philo);
		pthread_mutex_unlock(&philo->forks_lock);
	}
}

void	philo_drop_forks(t_philo *philo)
{
	int	fork_left_held;
	int	fork_right_held;

	pthread_mutex_lock(&philo->philo_lock);
	fork_left_held = philo->fork_left_flag;
	fork_right_held = philo->fork_right_flag;
	philo->fork_right_flag = 0;
	philo->fork_left_flag = 0;
	pthread_mutex_unlock(&philo->philo_lock);
	if (fork_right_held)
		pthread_mutex_unlock(&philo->table->forks[philo->fork_right]);
	if (fork_left_held)
		pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
}
