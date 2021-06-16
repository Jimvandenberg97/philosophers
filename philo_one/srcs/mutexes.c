/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutexes.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:59:59 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/23 10:38:32 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutexes_init(t_settings *settings)
{
	size_t	i;

	i = 0;
	while (i < settings->num_philo)
	{
		if (pthread_mutex_init(&settings->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&settings->m_screen, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&settings->m_stop, NULL) != 0)
		return (0);
	return (1);
}
