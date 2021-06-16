/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 12:53:38 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/03/01 11:22:37 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "utils.h"

void	philo_take_forks(t_philo *philo)
{
	if (philo->settings->stop == 1)
		return ;
	sem_wait(philo->settings->s_forks);
	sem_wait(philo->settings->s_screen);
	printaction(philo, ACTION_FORK);
	sem_post(philo->settings->s_screen);
	sem_wait(philo->settings->s_forks);
	sem_wait(philo->settings->s_screen);
	printaction(philo, ACTION_FORK);
	sem_post(philo->settings->s_screen);
}

void	philo_eat(t_philo *philo)
{
	if (philo->settings->stop == 1)
		return ;
	sem_wait(philo->settings->s_screen);
	printaction(philo, ACTION_EAT);
	sem_post(philo->settings->s_screen);
	philo->last_eat = timestamp_get(philo->settings);
	stupid_sleep(philo->settings, philo->settings->time_eat);
	sem_post(philo->settings->s_forks);
	sem_post(philo->settings->s_forks);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->settings->stop == 1)
		return ;
	sem_wait(philo->settings->s_screen);
	printaction(philo, ACTION_SLEEP);
	sem_post(philo->settings->s_screen);
	if (philo->settings->stop == 1)
		return ;
	stupid_sleep(philo->settings, philo->settings->time_sleep);
}

void	philo_think(t_philo *philo)
{
	if (philo->settings->stop == 1)
		return ;
	sem_wait(philo->settings->s_screen);
	printaction(philo, ACTION_THINK);
	sem_post(philo->settings->s_screen);
}
