/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: JKCTech <admin@jkctech.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 15:18:43 by JKCTech       #+#    #+#                 */
/*   Updated: 2021/02/09 15:53:58 by JKCTech       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

void	ft_putnbr(long n)
{
	char	c;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	c = (n % 10) + '0';
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}
