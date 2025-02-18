/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:59:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/18 13:10:20 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_args(char **argv, char **args)
{
	if (check_empty(argv) || check_syntax(args) || check_overflow(args))
	{
		free_array(args);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
}
