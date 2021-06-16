/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 13:08:53 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/23 10:39:20 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

int	settings_cleanup(t_settings *settings)
{
	size_t	i;

	if (settings->philos != NULL)
	{
		i = 0;
		while (i < settings->num_philo)
		{
			pthread_mutex_destroy(&settings->forks[i]);
			i++;
		}
		free(settings->philos);
	}
	pthread_mutex_destroy(&settings->m_screen);
	pthread_mutex_destroy(&settings->m_stop);
	free(settings->forks);
	free(settings);
	return (1);
}
