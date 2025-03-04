/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:59:07 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/04 17:46:38 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_death(t_philo *philo)
{
	long	interval;

	pthread_mutex_lock(&philo->philo_lock);
	interval = get_time() - philo->last_meal_time;
	if (interval > philo->table->tt_die)
	{
		pthread_mutex_lock(&philo->table->table_lock);
		philo->table->someone_died = 1;
		pthread_mutex_unlock(&philo->table->table_lock);
	}
	if (philo->table->someone_died == 1)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d died\n", interval, philo->philo_id);
		pthread_mutex_unlock(&philo->table->print_mutex);
		pthread_mutex_unlock(&philo->philo_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo_lock);
	return (0);
}
