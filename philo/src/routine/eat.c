/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:57:46 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/07 16:34:43 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_eat(t_philo *philo)
{
	if (is_dead(philo))
	{
		philo_drop_forks(philo);
		return ;
	}
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
