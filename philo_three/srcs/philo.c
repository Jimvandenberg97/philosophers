/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 12:00:40 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/23 13:03:48 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "utils.h"
#include <sys/wait.h>
#include <signal.h>

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

void	philos_kill(t_settings *settings)
{
	size_t	i;

	i = 0;
	while (i < settings->num_philo)
	{
		kill(settings->philos[i].pid, SIGKILL);
		i++;
	}
}

void	philo_watcher(t_settings *settings)
{
	int		status;
	size_t	i;
	int		ex;
	size_t	done;

	i = 0;
	done = 0;
	while (i < settings->num_philo)
	{
		ex = waitpid(settings->philos[i].pid, &status, WNOHANG);
		if (ex > 0 && WIFEXITED(status) && WEXITSTATUS(status) == 0)
			done++;
		if ((ex > 0 && WIFEXITED(status) && WEXITSTATUS(status))
			|| done == settings->num_philo)
		{
			philos_kill(settings);
			return ;
		}
		i++;
		if (i == settings->num_philo)
			i = 0;
	}
}

static void	*philo_monitor_local(void *phil)
{
	t_philo	*philo;

	philo = (t_philo*)phil;
	while (1)
	{
		if (timestamp_get(philo->settings)
			> philo->last_eat + philo->settings->time_die)
		{
			sem_wait(philo->settings->s_screen);
			printaction(philo, ACTION_DIE);
			exit(1);
			break ;
		}
	}
	return (NULL);
}

int	philo_loop(t_philo *philo)
{
	int			i;

	i = 0;
	philo->last_eat = timestamp_get(philo->settings);
	if (pthread_create(&philo->thread, NULL, &philo_monitor_local,
			(void*)philo) != 0)
		return (0);
	while (philo->settings->num_eat == -1 || i < philo->settings->num_eat)
	{
		i++;
		philo_take_forks(philo);
		philo_eat(philo);
		if (philo->settings->num_eat != -1 && i == philo->settings->num_eat)
			return (EXIT_SUCCESS);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (EXIT_FAILURE);
}
