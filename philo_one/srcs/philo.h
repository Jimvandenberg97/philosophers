/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:56:13 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/26 10:54:39 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stddef.h>

# define ACTION_FORK " has taken a fork\n"
# define ACTION_EAT " is eating\n"
# define ACTION_SLEEP " is sleeping\n"
# define ACTION_THINK " is thinking\n"
# define ACTION_DIE " has died\n"

typedef struct s_philo	t_philo;

typedef struct s_settings {
	size_t				start_s;
	size_t				start_us;
	size_t				num_philo;
	size_t				time_die;
	size_t				time_eat;
	size_t				time_sleep;
	int					num_eat;
	size_t				stop;
	size_t				eat_done;
	pthread_mutex_t		m_screen;
	pthread_mutex_t		m_stop;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}						t_settings;

struct					s_philo {
	t_settings			*settings;
	size_t				num;
	size_t				last_eat;
	size_t				done;
	size_t				alive;
	pthread_t			thread;
	pthread_mutex_t		*m_fork_left;
	pthread_mutex_t		*m_fork_right;
};

/*
** Settings
*/
int						settings_cleanup(t_settings *settings);
void					starttime_set(t_settings *settings);
size_t					timestamp_get(t_settings *settings);

/*
** Philo
*/
int						philos_init(t_philo *philos, t_settings *settings);
int						init_philos(t_settings	*settings);
void					philo_take_forks(t_philo *philo);
void					philo_eat(t_philo *philo);
void					philo_sleep(t_philo *philo);
void					philo_think(t_philo *philo);

/*
** Mutexes
*/
int						mutexes_init(t_settings *settings);

int						monitor(t_settings *settings);
void					*monitor_local(void *phil);

#endif
