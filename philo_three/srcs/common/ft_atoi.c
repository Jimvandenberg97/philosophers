/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:11:36 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/23 10:21:45 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long int	total;
	long int	multiplier;

	total = 0;
	multiplier = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		multiplier = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		total *= 10;
		total += *str - '0';
		if ((total * multiplier < INT_MIN) || (total * multiplier > INT_MAX))
			return ((total * multiplier < INT_MIN) - 1);
		str++;
	}
	return (total * multiplier);
}

int	ft_atoi_valid(const char *str)
{
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
