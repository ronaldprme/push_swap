/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:58:44 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:17:03 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux1(char c, unsigned int u, int *count)
{
	if (c == 'u')
		ft_putnbru(u, count);
	if (c == 'x' || c == 'X')
		ft_convert_int(u, c, count);
}

void	ft_aux2(char c, int n, int *count)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(n, count);
	if (c == 'c')
		ft_putchar((char)(n), count);
}

void	ft_aux3(unsigned long p, int *count)
{
	if (p == 0)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	else
	{
		ft_putstr("0x", count);
		ft_pointer(p, count);
	}
}
