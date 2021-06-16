/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 12:00:40 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/03/01 11:21:26 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "utils.h"

int	philos_init(t_philo *philos, t_settings *settings)
{
	size_t		i;

	i = 0;
	while (i < settings->num_philo)
	{
		philos[i].settings = settings;
		philos[i].num = i + 1;
		i++;
	}
	return (1);
}

static void	philo_monitor(t_settings *settings)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (settings->eat_done == settings->num_philo)
		{
			sem_wait(settings->s_screen);
			sem_post(settings->s_stop);
			return ;
		}
		if (settings->philos[i].done == 0 && timestamp_get(settings)
			> settings->philos[i].last_eat + settings->time_die)
		{
			sem_wait(settings->s_screen);
			printaction(&settings->philos[i], ACTION_DIE);
			settings->stop = 1;
			sem_post(settings->s_stop);
			return ;
		}
		i++;
		if (i >= settings->num_philo)
			i = 0;
	}
}

static void	*philo_loop(void *phil)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo*)phil;
	i = 0;
	philo->last_eat = timestamp_get(philo->settings);
	while (!philo->settings->stop && (philo->settings->num_eat == -1
			|| i < philo->settings->num_eat))
	{
		i++;
		philo_take_forks(philo);
		philo_eat(philo);
		if (philo->settings->num_eat != -1 && i == philo->settings->num_eat)
		{
			philo->settings->eat_done++;
			philo->done = 1;
			return (NULL);
		}
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	init_philos(t_settings *settings)
{
	size_t		i;

	i = 0;
	while (i < settings->num_philo)
	{
		if (pthread_create(&settings->philos[i].thread, NULL, &philo_loop,
				&settings->philos[i]) != 0)
			return (0);
		pthread_detach(settings->philos[i].thread);
		usleep(100);
		i++;
	}
	philo_monitor(settings);
	return (1);
}
