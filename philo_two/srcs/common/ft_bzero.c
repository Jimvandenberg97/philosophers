/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoopman <jkoopman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:40:14 by jkoopman      #+#    #+#                 */
/*   Updated: 2021/02/23 14:41:17 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
