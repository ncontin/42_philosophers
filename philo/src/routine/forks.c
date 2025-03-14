/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:56:41 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/14 11:20:45 by ncontin          ###   ########.fr       */
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
	pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
	philo->fork_left_flag = 1;
	print_fork_taken(philo);
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
	philo->fork_right_flag = 1;
	print_fork_taken(philo);
}

void	philo_take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		odd_take_forks(philo);
	else
		even_take_forks(philo);
}

void	philo_drop_forks(t_philo *philo)
{
	if (philo->fork_left_flag == 1)
		pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
	if (philo->fork_right_flag == 1)
		pthread_mutex_unlock(&philo->table->forks[philo->fork_right]);
	pthread_mutex_lock(&philo->philo_lock);
	philo->fork_right_flag = 0;
	philo->fork_left_flag = 0;
	pthread_mutex_unlock(&philo->philo_lock);
}
