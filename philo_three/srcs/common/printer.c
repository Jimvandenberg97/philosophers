/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 10:37:57 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/03/01 11:13:30 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "utils.h"

void	printaction(t_philo *philo, char *action)
{
	ft_putnbr(timestamp_get(philo->settings));
	write(1, " ", 1);
	ft_putnbr(philo->num);
	write(1, action, ft_strlen(action));
}

/*
** This is for mac specifically...
*/

void	stupid_sleep(t_settings *settings, size_t ms)
{
	size_t	start;

	ms *= 1000;
	start = usec_get(settings);
	while (usec_get(settings) - start < ms)
		usleep(500);
}
