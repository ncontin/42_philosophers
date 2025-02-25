/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:28:42 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/25 15:29:51 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	free_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nbr)
	{
		pthread_mutex_destroy(&table->forks[i++]);
	}
	free(table->forks);
}
