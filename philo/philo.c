/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/26 12:58:20 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	i = 0;
	if (parse_args(argv, argc, &table) == 1)
		return (1);
	if (init_data(&table) == 1)
		return (1);
	while (i < table.philos_nbr)
	{
		pthread_create(&table.philos[i].thread, NULL, &start_routine,
			&table.philos[i]);
		i++;
	}
	while (i-- > 0)
	{
		pthread_join(table.philos[i].thread, NULL);
	}
	free(table.philos);
	free_forks(&table);
}

/* Steps to Implement the Asymmetric Solution
Initialize Mutexes

Create an array of mutexes, one for each fork.

Philosopher Routine

Each philosopher runs a loop:

Think for a random amount of time.

Attempt to pick up forks:

If the philosopher’s ID is even, pick up the left fork first,
	then the right fork.

If the philosopher’s ID is odd, pick up the right fork first,
	then the left fork.

Eat for a random amount of time.

Put down both forks.

Avoiding Deadlocks

By having even and odd philosophers pick up forks in a different order,
	you ensure that at least one philosopher can always proceed. */
