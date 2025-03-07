/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:00:50 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/07 16:32:08 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_sleep(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d is sleeping\n", get_time() - philo->table->start_time,
		philo->philo_id);
	pthread_mutex_unlock(&philo->table->print_mutex);
	ft_usleep(philo->table->tt_sleep);
}
