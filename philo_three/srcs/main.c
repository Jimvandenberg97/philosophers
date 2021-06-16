/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:21:10 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/03/01 11:25:17 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "utils.h"

static int	init_philos(t_settings *settings)
{
	size_t		i;

	i = 0;
	while (i < settings->num_philo)
	{
		settings->philos[i].pid = fork();
		if (settings->philos[i].pid == 0)
			exit(philo_loop(&settings->philos[i]));
		else if (settings->philos[i].pid < 0)
			return (0);
		usleep(100);
		i++;
	}
	philo_watcher(settings);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_settings	*settings;

	if (args_validate(argc, argv) == 0)
		return (1);
	settings = settings_init(argc, argv);
	if (settings == NULL)
		return (1);
	settings->philos = ft_calloc(1, sizeof(t_philo) * settings->num_philo);
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
