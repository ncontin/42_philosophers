/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:47 by ncontin           #+#    #+#             */
/*   Updated: 2025/05/12 11:51:34 by ncontin          ###   ########.fr       */
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

typedef struct s_philo
{
	int				philo_id;
	int				fork_left;
	int				fork_right;
	int				fork_left_flag;
	int				fork_right_flag;
	int				meals_eaten;
	long			last_meal_time;
	int				is_full;
	pthread_mutex_t	forks_lock;
	pthread_t		thread;
	pthread_mutex_t	philo_lock;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				philos_nbr;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	int				meals_per_philo;
	int				someone_died;
	long			start_time;
	int				end_dinner;
	int				full_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_t		monitor;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	table_lock;
	t_philo			*philos;
}					t_table;

int					create_threads(t_table *table);
int					join_threads(t_table *table);

// memory
int					cleanup(t_table *table);
void				free_array(char **array);
void				free_all(t_table *table);
int					destroy(t_table *table);

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
long int			ft_atol(const char *nptr);

// time
size_t				get_time(void);
int					ft_usleep(size_t milliseconds);

// init
int					init_data(t_table *table);

// routine
int					is_dead(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_take_forks(t_philo *philo);
void				print_fork_taken(t_philo *philo);
void				philo_drop_forks(t_philo *philo);
void				philo_sleep(t_philo *philo);
int					is_full(t_philo *philo);
void				philo_think(t_philo *philo);
void				*start_routine(void *arg);
void				*monitor_philos(void *arg);

#endif
