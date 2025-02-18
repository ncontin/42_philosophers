/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:47 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/18 12:40:18 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philosopher
{
	int				philo_id;
	int				fork_left;
	int				fork_right;
}					t_philosopher;

typedef struct s_table
{
	int				philos_nbr;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				meals_per_philo;
	pthread_mutex_t	*forks;
}					t_table;

long int			ft_atol(const char *nptr);

#endif
