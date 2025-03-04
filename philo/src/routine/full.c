/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:58:53 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/04 12:48:38 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_meals(t_philo *philo)
{
	if (philo->meals_eaten >= philo->table->meals_per_philo
		&& philo->table->meals_per_philo != -1)
		return (1);
	return (0);
}
int	is_full(t_philo *philo)
{
	if (check_meals(philo) == 1)
	{
		// pthread_mutex_lock(&philo->table->print_mutex);
		// printf("%ld %d is done\n", get_time() - philo->table->start_time,
		// 	philo->philo_id);
		// pthread_mutex_unlock(&philo->table->print_mutex);
		return (1);
	}
	return (0);
}
