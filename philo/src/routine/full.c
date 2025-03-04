/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:58:53 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/04 15:42:28 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	is_full(t_philo *philo)
{
	if (philo->meals_eaten >= philo->table->meals_per_philo
		&& philo->table->meals_per_philo != -1)
		return (1);
	return (0);
}
