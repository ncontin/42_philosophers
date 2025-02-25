/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:47 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/25 17:21:07 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	int				philo_id;
	int				fork_left;
	int				fork_right;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	meal_lock;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				philos_nbr;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				meals_per_philo;
	long			start_time;
	int end_dinner; // boolean
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_table;

long int			ft_atol(const char *nptr);

// memory
void				free_array(char **array);
void				free_forks(t_table *table);

// parsing
int					parse_args(char **argv, int argc, t_table *table);

// checks
int					check_args(char **argv, char **args);
int					check_empty(char **args);
int					check_overflow(char **args);
int					check_syntax(char **args);

// utils
long int			ft_atol(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isdigit(int c);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strtrim(char const *s1, char const *set);

// time
size_t				get_time(void);
int					ft_usleep(size_t milliseconds);

// init
int					init_data(t_table *table);

// dinner
void				*start_routine(void *arg);

#endif
