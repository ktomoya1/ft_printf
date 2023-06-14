/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:06:08 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/14 18:13:08 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	checkflag(const char *flag, va_list args, ssize_t chars, int fd)
{
	if (*flag == 'c')
		chars = ft_putchar_fd(va_arg(args, int), fd);
	else if (*flag == 's')
		chars = ft_putstr_fd(va_arg(args, char *), fd);
	else if (*flag == 'p')
	{
		chars = ft_putstr_fd("0x", fd);
		chars += put_ptr_fd(va_arg(args, uintptr_t), "0123456789abcdef", fd);
	}
	else if (*flag == 'd' || *flag == 'i')
		chars = put_int_fd(va_arg(args, int), "0123456789", fd);
	else if (*flag == 'u')
		chars = put_uint_fd(va_arg(args, unsigned int), "0123456789", fd);
	else if (*flag == 'x')
		chars = put_uint_fd(va_arg(args, unsigned int), "0123456789abcdef", fd);
	else if (*flag == 'X')
		chars = put_uint_fd(va_arg(args, unsigned int), "0123456789ABCDEF", fd);
	else if (*flag == '%')
		chars = ft_putchar_fd('%', fd);
	else
		chars = ft_putchar_fd(*flag, fd);
	return (chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	chars;

	va_start(args, format);
	chars = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format != '\0' && ft_strchr("cspdiuxX%%", *format) != NULL)
				chars += checkflag(format, args, chars, STDOUT_FILENO);
			else
				return (chars);
		}
		else
			chars += ft_putchar_fd(*format, STDOUT_FILENO);
		format++;
	}
	va_end(args);
	return ((int)chars);
}
