/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:10:06 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/19 11:11:44 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "philo.h"

int			ft_isdigit(char c);
int			ft_atoi(const char *str);
int			ft_atoi_valid(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		ft_putnbr(long n);
size_t		ft_strlen(const char *str);

t_settings	*settings_init(int argc, char *argv[]);
int			args_validate(int argc, char *argv[]);

void		printaction(t_philo *philo, char *action);

void		stupid_sleep(t_settings *settings, size_t ms);
size_t		usec_get(t_settings *settings);
void		starttime_set(t_settings *settings);
size_t		timestamp_get(t_settings *settings);

#endif
