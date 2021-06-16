/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 12:53:38 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/03/01 11:07:16 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "utils.h"

void	philo_take_forks(t_philo *philo)
{
	if (philo->settings->stop == 1)
		return ;
	pthread_mutex_lock(philo->m_fork_left);
	pthread_mutex_lock(&philo->settings->m_screen);
	printaction(philo, ACTION_FORK);
	pthread_mutex_unlock(&philo->settings->m_screen);
	pthread_mutex_lock(philo->m_fork_right);
	pthread_mutex_lock(&philo->settings->m_screen);
	printaction(philo, ACTION_FORK);
	pthread_mutex_unlock(&philo->settings->m_screen);
}

void	philo_eat(t_philo *philo)
{
	if (philo->settings->stop == 1)
		return ;
	pthread_mutex_lock(&philo->settings->m_screen);
	printaction(philo, ACTION_EAT);
	pthread_mutex_unlock(&philo->settings->m_screen);
	philo->last_eat = timestamp_get(philo->settings);
	stupid_sleep(philo->settings, philo->settings->time_eat);
	pthread_mutex_unlock(philo->m_fork_left);
	pthread_mutex_unlock(philo->m_fork_right);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->settings->stop == 1)
		return ;
	pthread_mutex_lock(&philo->settings->m_screen);
	printaction(philo, ACTION_SLEEP);
	pthread_mutex_unlock(&philo->settings->m_screen);
	if (philo->settings->stop == 1)
		return ;
	stupid_sleep(philo->settings, philo->settings->time_sleep);
}

void	philo_think(t_philo *philo)
{
	if (philo->settings->stop == 1)
		return ;
	pthread_mutex_lock(&philo->settings->m_screen);
	printaction(philo, ACTION_THINK);
	pthread_mutex_unlock(&philo->settings->m_screen);
}
