/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   semaphores.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:59:59 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/23 13:12:48 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <fcntl.h>
#include <sys/stat.h>

int	semaphores_init(t_settings *settings)
{
	sem_unlink("screen");
	sem_unlink("stop");
	sem_unlink("forks");
	settings->s_screen = sem_open("screen", O_CREAT | O_EXCL, S_IRWXU, 1);
	settings->s_stop = sem_open("stop", O_CREAT | O_EXCL, S_IRWXU, 1);
	settings->s_forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU,
			settings->num_philo);
	if (settings->s_screen == SEM_FAILED || settings->s_stop == SEM_FAILED
		|| settings->s_forks == SEM_FAILED)
		return (0);
	return (1);
}
