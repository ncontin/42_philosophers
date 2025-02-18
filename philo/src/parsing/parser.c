/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:08:13 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/18 13:11:18 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*join_args(char **argv)
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

char	**parse_args(char **argv)
{
	char	*joined;
	char	**args;

	joined = join_args(argv + 1);
	if (!joined)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	args = ft_split(joined, ' ');
	free(joined);
	return (args);
}
