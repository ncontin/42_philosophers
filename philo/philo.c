/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/18 16:50:22 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_table(t_table *table)
{
	table->philos_nbr = -1;
	table->tt_die = -1;
	table->tt_eat = -1;
	table->tt_sleep = -1;
	table->meals_per_philo = -1;
}

static t_table	*set_table(char **args, t_table *table)
{
	init_table(table);
	table->philos_nbr = ft_atol(args[0]);
	table->tt_die = ft_atol(args[1]);
	table->tt_eat = ft_atol(args[2]);
	table->tt_sleep = ft_atol(args[3]);
	if (args[4])
		table->meals_per_philo = ft_atol(args[4]);
	free_array(args);
	return (table);
}

static int	check_argc(int argc)
{
	if (argc > 6)
	{
		write(2, "Too many arguments\n", 18);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	*table;
	char	**args;

	table = NULL;
	if (check_argc(argc))
		return (1);
	args = parse_args(argv);
	if (check_args(argv, args) == 1)
		return (1);
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	table = set_table(args, table);
	printf("philos nbr: %d\n", table->philos_nbr);
	free(table);
}

// parsing

/* 1st number_of_philosophers: The number of philosophers and also the number
of forks.


2nd: time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the sim-
ulation, they die.

3rd: time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

4th: time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

5th: number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies. */

/* pseudo code
array of chopsticks[5], 5 = same number of philos
each chopsticks init at 1, it means is free
when a philo grab a chopstick we set the value to 0;

struct of philo[i]

do {
wait (chopstick[i])
wait (chopstick[(i +1 ) % 5]) we use remainder because of the last philo

//eat
signal(chopstick[i])
signal(chopstick[(i + 1) % 5])

//think

} while (true)

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
