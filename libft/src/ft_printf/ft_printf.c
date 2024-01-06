/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:58:50 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 15:58:53 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux_printf(const char *format, va_list args, int *count)
{
	int	i;
	int	len;

	len = ft_strlen(format);
	i = 0;
	while (i < len)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				ft_putchar('%', count);
			else if (format[i] == 's')
				ft_putstr(va_arg(args, char *), count);
			else if (format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
				ft_aux1((format[i]), va_arg(args, unsigned int), count);
			else if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i')
				ft_aux2((format[i]), va_arg(args, int), count);
			else if (format[i] == 'p')
				ft_aux3(va_arg(args, unsigned long), count);
		}
		else
			ft_putchar(format[i], count);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int				count;
	va_list			args;

	va_start(args, format);
	count = 0;
	ft_aux_printf(format, args, &count);
	va_end(args);
	return (count);
}
