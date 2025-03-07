/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:00:50 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/05 17:19:11 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->someone_died == 1)
	{
		pthread_mutex_unlock(&philo->table->table_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->table->table_lock);
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d is sleeping\n", get_time() - philo->table->start_time,
		philo->philo_id);
	pthread_mutex_unlock(&philo->table->print_mutex);
	ft_usleep(philo->table->tt_sleep);
}
