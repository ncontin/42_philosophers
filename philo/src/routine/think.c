/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:58:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/11 11:46:48 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d is thinking\n", get_time() - philo->table->start_time,
		philo->philo_id);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
