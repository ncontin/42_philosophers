/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:40 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/07 16:57:05 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(50);
	while (!is_dead(philo) && !is_full(philo))
	{
		if (philo->table->philos_nbr == 1)
			return (NULL);
		philo_take_forks(philo);
		philo_eat(philo);
		philo_drop_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
