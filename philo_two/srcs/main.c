/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:21:10 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/23 12:45:19 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"
#include "utils.h"

int	main(int argc, char *argv[])
{
	t_settings	*settings;

	if (args_validate(argc, argv) == 0)
		return (1);
	settings = settings_init(argc, argv);
	if (settings == NULL)
		return (1);
	settings->philos = ft_calloc(settings->num_philo, sizeof(t_philo));
	if (settings->philos == NULL)
		return (settings_cleanup(settings));
	if (!semaphores_init(settings) || !philos_init(settings->philos, settings))
		return (settings_cleanup(settings));
	starttime_set(settings);
	if (init_philos(settings) == 0)
		return (settings_cleanup(settings));
	settings_cleanup(settings);
	return (0);
}
