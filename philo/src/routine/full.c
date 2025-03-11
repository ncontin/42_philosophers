/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:58:53 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/11 11:58:35 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_full(t_philo *philo)
{
	if (philo->meals_eaten >= philo->table->meals_per_philo
		&& philo->table->meals_per_philo != -1)
	{
		pthread_mutex_lock(&philo->philo_lock);
		philo->is_full = 1;
		pthread_mutex_unlock(&philo->philo_lock);
		return (1);
	}
	return (0);
}
