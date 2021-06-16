/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 13:08:53 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/23 11:10:45 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

int	settings_cleanup(t_settings *settings)
{
	if (settings->philos != NULL)
		free(settings->philos);
	free(settings);
	sem_unlink("screen");
	sem_unlink("stop");
	sem_unlink("forks");
	return (1);
}
