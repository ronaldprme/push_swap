/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:58:37 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 15:58:40 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru(unsigned int n, int *count)
{
	if (n <= UINT_MAX)
	{
		if (n > 9)
		{
			ft_putnbru((n / 10), count);
			ft_putnbru((n % 10), count);
		}
		else
		{
			ft_putchar((n + '0'), count);
		}
	}
}

void	ft_convert_int(unsigned int n, char c, int *count)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(base[n], count);
	if (n >= 16)
	{
		ft_convert_int (n / 16, c, count);
		ft_convert_int (n % 16, c, count);
	}
}

void	ft_pointer(unsigned long p, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (p < 16)
		ft_putchar(base[p], count);
	if (p >= 16)
	{
		ft_pointer (p / 16, count);
		ft_pointer (p % 16, count);
	}
}
