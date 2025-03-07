/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:57:46 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/05 17:18:58 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->someone_died == 1)
	{
		pthread_mutex_unlock(&philo->table->table_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->table->table_lock);
	// EAT
	pthread_mutex_lock(&philo->philo_lock);
	philo->last_meal_time = get_time();
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d is eating\n", get_time() - philo->table->start_time,
		philo->philo_id);
	pthread_mutex_unlock(&philo->table->print_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->philo_lock);
	ft_usleep(philo->table->tt_eat);
}
