/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 12:00:40 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/03/01 11:28:49 by JKCTech       ########   odam.nl         */
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
		philos[i].last_eat = 0;
		philos[i].done = 0;
		philos[i].alive = 1;
		philos[i].m_fork_left = &settings->forks[i];
		philos[i].m_fork_right = &settings->forks[(i + 1)
			% settings->num_philo];
		i++;
	}
	return (1);
}

static int	check_eatgoal(t_philo *philo, int i)
{
	if (philo->settings->num_eat != -1 && i == philo->settings->num_eat)
	{
		philo->settings->eat_done++;
		philo->done = 1;
		return (0);
	}
	return (1);
}

static void	*philo_loop(void *phil)
{
	t_philo		*philo;
	int			i;
	pthread_t	monitor;

	philo = (t_philo*)phil;
	i = 0;
	philo->last_eat = timestamp_get(philo->settings);
	while (!philo->settings->stop && (philo->settings->num_eat == -1
			|| i < philo->settings->num_eat))
	{
		i++;
		pthread_detach(monitor);
		pthread_create(&monitor, NULL, &monitor_local, phil);
		philo_take_forks(philo);
		philo_eat(philo);
		if (!check_eatgoal(philo, i))
			return (NULL);
		philo_sleep(philo);
		philo_think(philo);
	}
	philo->alive = 0;
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
	return (1);
}
