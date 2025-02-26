/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:40 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/26 13:18:34 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 != 0)
		ft_usleep(500);
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
		pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
		pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
		printf("%ld %d has taken a fork\n", get_time()
			- philo->table->start_time, philo->philo_id);
	}
}

void	philo_eat(t_philo *philo)
{
	// EAT
	printf("%ld %d is eating\n", get_time() - philo->table->start_time,
		philo->philo_id);
	philo->meals_eaten++;
	philo->last_meal_time = get_time();
	ft_usleep(philo->table->tt_eat);
}

void	philo_think(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_time() - philo->table->start_time,
		philo->philo_id);
}

int	check_death(t_philo *philo)
{
	if (get_time() - philo->last_meal_time > philo->table->tt_die)
	{
		printf("%ld %d is dead\n", get_time() - philo->table->start_time,
			philo->philo_id);
		return (1);
	}
	return (0);
}

int	check_full(t_philo *philo)
{
	if (philo->meals_eaten == philo->table->meals_per_philo)
	{
		printf("philos is full");
		return (1);
	}
	return (0);
}
int	monitor(t_philo *philo)
{
	if (check_death(philo) == 1 || check_full(philo) == 1)
		return (1);
	ft_usleep(500);
	return (0);
}

void	philo_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
	// printf("%ld Philosopher %d has put down and unlocked fork left n: %d\n",
	// 	get_time() - philo->table->start_time, philo->philo_id,
	// 	philo->fork_left);
	pthread_mutex_unlock(&philo->table->forks[philo->fork_right]);
	// printf("%ld Philosopher %d has put down and unlocked fork right n: %d\n",
	// 	get_time() - philo->table->start_time, philo->philo_id,
	// 	philo->fork_right);
}

void	philo_sleep(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_time() - philo->table->start_time,
		philo->philo_id);
	ft_usleep(philo->table->tt_sleep);
}
void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->table->start_time = get_time();
	while (1)
	{
		philo_take_forks(philo);
		philo_eat(philo);
		philo_drop_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (monitor(philo) == 1)
			return (NULL);
	}
	// check_dead or limit reached
	return (NULL);
}

// void	monitor_routine(void)
// {
// }
