/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/20 18:49:16 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	table->philos = philos;
	while (i < table->philos_nbr)
	{
		table->philos->philo_id = i++;
		printf("philo id: %d\n", table->philos->philo_id);
	}
}

void	test(void)
{
	printf("start\n");
	// ft_usleep(3000);
	printf("end\n");
}

void	print_table(t_table *table)
{
	printf("philos_nbr: %d\n", table->philos_nbr);
	printf("tt_die: %d\n", table->tt_die);
	printf("tt_eat: %d\n", table->tt_eat);
	printf("tt_sleep: %d\n", table->tt_sleep);
	printf("meals_per_philo: %d\n", table->meals_per_philo);
}

// void	start_dinner(t_table *table, t_philosopher *philo)
// {
// }

int	main(int argc, char **argv)
{
	t_table	table[1];
	t_philo	*philos;

	if (parse_args(argv, argc, table) == 1)
		return (1);
	philos = malloc(sizeof(t_philo) * table->philos_nbr);
	if (!philos)
		return (1);
	init_philos(table, philos);
	test();
	print_table(table);
	free(philos);
}

/* pseudo code
array of chopsticks[5], 5 = same number of philos
each chopsticks init at 1, it means is free
when a philo grab a chopstick we set the value to 0;

// 3 ways to avoid deadlocks
1 allow at most four philos to be sitting simultaneously
2 allow a philo to pick up a chopstick only if both are available
3 asymmetric solution,
	an odd philo picks up first his left chopstick and then his right chopstick,
an even philo picks up his right chops and the his left chops
 */

/* The waiter solution to Dining Philosophers
The waiter solution provides a simple way to solve the Dining Philosophers problem,
	assuming an external entity called the waiter.

Strategy:

Every philosopher must request each of their (shared) chopsticks from a waiter,
	who may refuse the request at first in order to avoid a deadlock.

For convenience,
	we assume that all philosophers request their left chopstick first,
	then their right chopstick.

The waiter always provides chopsticks upon request unless only one chopstick remains unused. In that case,
	the waiter honors the request only if a right chopstick is requested; requests for a left chopstick are deferred until another philosopher finishes eating.

Argument for correct deadlock avoidance: The last chopstick will only be assigned if the waiter is certain that at least one philosopher can finish eating (thereupon releasing chopsticks). Therefore,
	the "circular wait" required for deadlock can't occur.

No starvation; fairness (depending on your waiter); degree of concurrency...

Downside: Scalability (the waiter could become a bottleneck if the number of processors is large). */
