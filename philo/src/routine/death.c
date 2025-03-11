/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:46:40 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/11 11:45:20 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->someone_died == 1)
	{
		pthread_mutex_unlock(&philo->table->table_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->table_lock);
	return (0);
}
