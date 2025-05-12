/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/05/12 11:51:04 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (parse_args(argv, argc, &table) == 1)
		return (1);
	if (init_data(&table) == 1)
		return (1);
	if (create_threads(&table) == 1)
		return (1);
	if (join_threads(&table) == 1)
		return (1);
	if (cleanup(&table) == 1)
		return (1);
	return (0);
}
