/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:52:18 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:27:09 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbru(unsigned int n, int *count);
void	ft_pointer(unsigned long p, int *count);
void	ft_convert_int(unsigned int n, char c, int *count);
void	ft_aux1(char c, unsigned int u, int *count);
void	ft_aux2(char c, int n, int *count);
void	ft_aux3(unsigned long p, int *count);
void	ft_aux_printf(const char *format, va_list args, int *count);

int		ft_strlen(const char *str);
int		ft_printf(const char *format, ...);

#endif