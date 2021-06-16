/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoopman <jkoopman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:31:26 by jkoopman      #+#    #+#                 */
/*   Updated: 2021/02/23 10:22:49 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
