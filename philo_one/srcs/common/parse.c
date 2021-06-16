/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:37:17 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/03/01 11:18:39 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <sys/time.h>
#include <stdio.h>

int	args_validate(int argc, char *argv[])
{
	int		i;

	if (argc < 5 || argc > 6)
	{
		printf("Correct syntax: %s num_philo time_die time_eat "
			"time_sleep [number_of_eat]\n",
			argv[0]);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi_valid(argv[i]))
		{
			printf("Invalid argument at parameter index %d.\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

t_settings	*settings_init(int argc, char *argv[])
{
	t_settings	*settings;

	settings = ft_calloc(1, sizeof(t_settings));
	if (settings == NULL)
		return (NULL);
	settings->num_philo = (size_t)ft_atoi(argv[1]);
	settings->time_die = (size_t)ft_atoi(argv[2]);
	settings->time_eat = (size_t)ft_atoi(argv[3]);
	settings->time_sleep = (size_t)ft_atoi(argv[4]);
	settings->num_eat = -1;
	if (argc == 6)
		settings->num_eat = ft_atoi(argv[5]);
	if (settings->num_philo < 1 || settings->time_die < 1
		|| settings->time_eat < 1 || settings->time_sleep < 1
		|| (argc == 6 && settings->num_eat < 1))
	{
		printf("Invalid input, are all numbers above 0?\n");
		free(settings);
		return (NULL);
	}
	return (settings);
}

void	starttime_set(t_settings *settings)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	settings->start_s = tv.tv_sec;
	settings->start_us = tv.tv_usec;
}

size_t	usec_get(t_settings *settings)
{
	struct timeval	tv;
	size_t			s_delta;

	gettimeofday(&tv, NULL);
	s_delta = tv.tv_sec - settings->start_s;
	return (
		((unsigned int)(s_delta * 1000000 + tv.tv_usec) - settings->start_us));
}

size_t	timestamp_get(t_settings *settings)
{
	struct timeval	tv;
	size_t			s_delta;

	gettimeofday(&tv, NULL);
	s_delta = tv.tv_sec - settings->start_s;
	return (
		((unsigned int)(s_delta * 1000000 + tv.tv_usec)
		- settings->start_us) / 1000);
}
