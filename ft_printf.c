/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:06:08 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/13 21:32:53 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	checktype(const char *type, va_list args, ssize_t chars, int fd)
{
	if (*type == 'c')
		chars = ft_putchar_fd(va_arg(args, int), fd);
	else if (*type == 's')
		chars = ft_putstr_fd(va_arg(args, char *), fd);
	else if (*type == 'p')
	{
		chars = ft_putstr_fd("0x", fd);
		chars += put_address_fd(va_arg(args, uintptr_t),
				"0123456789abcdef", fd);
	}
	else if (*type == 'd' || *type == 'i')
		chars = ft_putint_fd(va_arg(args, int), "0123456789", fd);
	else if (*type == 'u')
		chars = put_address_fd(va_arg(args, unsigned int), "0123456789", fd);
	else if (*type == 'x')
		chars = put_address_fd(va_arg(args, unsigned int),
				"0123456789abcdef", fd);
	else if (*type == 'X')
		chars = put_address_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", fd);
	else if (*type == '%')
		chars = ft_putchar_fd('%', fd);
	else
		chars = ft_putchar_fd(*type, fd);
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
			if (*format != '\0')
				chars += checktype(format, args, chars, STDOUT_FILENO);
		}
		else
			chars += ft_putchar_fd(*format, STDOUT_FILENO);
		format++;
	}
	va_end(args);
	return ((int)chars);
}

// int	main(void)
// {
// 	uintptr_t 	num;
// 	ssize_t		count1;
// 	ssize_t		count2;

// 	num = 1;
// 	// ft_printf(" NULL %s NULL \n", NULL);
// 	// printf(" NULL %s NULL \n", NULL);
// 	count1 = ft_printf(" %p ", &num);
// 	printf("\n");
// 	count2 = printf(" %p ", &num);
// 	printf("\n");
// 	printf("ft_count:%lu\n", count1);
// 	printf("count   :%lu\n", count2);
// }
