/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:06:08 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/11 21:27:31 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	check_flag(const char *format, va_list args, ssize_t count)
{
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char*));
	// else if (*format == 'p')
	// 	count += 1;
	// else if (*format == 'd')
	// 	count += 1;
	// else if (*format == 'i')
	// 	count += 1;
	// else if (*format == 'u')
	// 	count += 1;
	// else if (*format == 'x')
	// 	count += 1;
	// else if (*format == 'X')
	// 	count += 1;
	// else if (*format == '%')
	// 	count += 1;
	else
		count = ft_putchar(*format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format != '\0')
				count = check_flag(format, args, count);
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return ((int)count);
}

// int	main(void)
// {
// 	int	ft_count;
// 	int	count;

// 	ft_count = ft_printf("%c%c%c", '\0', '1', 1);
// 	printf("\n");
// 	count = printf("%c%c%c", '\0', '1', 1);
// 	printf("\n");
// 	printf("ft_count:%d\n", ft_count);
// 	printf("count   :%d\n", count);
// }
