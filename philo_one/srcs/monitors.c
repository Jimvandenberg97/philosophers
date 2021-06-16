/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitors.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 10:36:31 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/03/01 11:15:23 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <unistd.h>

int	monitor(t_settings *settings)
{
	if (settings->num_eat != -1)
	{
		while (!settings->stop && settings->eat_done < settings->num_philo)
			usleep(1000);
		if (settings->stop || settings->eat_done == settings->num_philo)
			return (0);
		if (!settings->stop && settings->eat_done == settings->num_philo)
			return (1);
	}
	else
	{
		while (!settings->stop)
			usleep(1000);
	}
	return (1);
}

void	*monitor_local(void *phil)
{
	t_philo			*philo;

	philo = (t_philo*)phil;
	stupid_sleep(philo->settings, philo->settings->time_die);
	if (philo->alive && timestamp_get(philo->settings) - philo->last_eat
		>= philo->settings->time_die)
	{
		pthread_mutex_lock(&philo->settings->m_screen);
		philo->settings->stop = 1;
		printaction(philo, ACTION_DIE);
	}
	return (NULL);
}
