/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:59:07 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/03 18:29:37 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_death(t_philo *philo)
{
	long	interval;
	long	current_time;

	pthread_mutex_lock(&philo->philo_lock);
	current_time = get_time();
	interval = current_time - philo->last_meal_time;
	if (interval > philo->table->tt_die)
		philo->table->someone_died = 1;
	if (philo->table->someone_died == 1)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("interval %ld %d someone died\n", get_time()
			- philo->last_meal_time, philo->philo_id);
		pthread_mutex_unlock(&philo->table->print_mutex);
		pthread_mutex_unlock(&philo->philo_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo_lock);
	return (0);
}
