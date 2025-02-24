/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/24 13:27:47 by ncontin          ###   ########.fr       */
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

void	init_table(t_table *table)
{
	table->
}
	void init_data(t_table *table)
{
	table->philos = malloc(sizeof(t_philo) * table->philos_nbr);
	if (!table->philos)
		return (1);
}

int	main(int argc, char **argv)
{
	t_table	table[1];

	if (parse_args(argv, argc, table) == 1)
		return (1);
	init_philos(table, philos);
	test();
	print_table(table);
	free(philos);
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
