/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:08:13 by ncontin           #+#    #+#             */
/*   Updated: 2025/03/07 16:56:37 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static char	*join_args(char **argv)
{
	int		i;
	char	*args;
	char	*tmp;

	args = ft_strdup("");
	if (!args)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		tmp = ft_strjoin(args, argv[i]);
		free(args);
		if (!tmp)
			return (NULL);
		args = ft_strjoin(tmp, " ");
		free(tmp);
		if (!args)
			return (NULL);
		i++;
	}
	return (args);
}

static int	check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Invalid input\n", 2);
		ft_putstr_fd("./philo nbr_philos tt_die tt_eat tt_sleep [nbr_meals]\n",
			2);
		return (1);
	}
	return (0);
}

static t_table	*set_table(char **args, t_table *table)
{
	table->philos_nbr = ft_atol(args[0]);
	table->tt_die = ft_atol(args[1]);
	table->tt_eat = ft_atol(args[2]);
	table->tt_sleep = ft_atol(args[3]);
	if (args[4])
		table->meals_per_philo = ft_atol(args[4]);
	else
		table->meals_per_philo = -1;
	free_array(args);
	return (table);
}

int	parse_args(char **argv, int argc, t_table *table)
{
	char	*joined;
	char	**args;

	if (check_argc(argc) == 1)
		return (1);
	joined = join_args(argv + 1);
	if (!joined)
		return (1);
	args = ft_split(joined, ' ');
	free(joined);
	if (check_args(argv, args) == 1)
		return (1);
	set_table(args, table);
	return (0);
}
