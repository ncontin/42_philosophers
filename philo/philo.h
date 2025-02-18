/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:47 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/18 15:55:18 by ncontin          ###   ########.fr       */
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

// memory
void				free_array(char **array);

// parsing
char				**parse_args(char **argv);

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

#endif
