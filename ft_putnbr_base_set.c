/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:09:58 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/14 18:47:13 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	put_ptr_fd(uintptr_t hexnbr, char *base, int fd)
{
	uintptr_t	base_len;
	ssize_t		chars;

	chars = 0;
	base_len = ft_strlen(base);
	if (hexnbr >= base_len)
		chars = put_ptr_fd(hexnbr / base_len, base, fd);
	chars += write(fd, &base[hexnbr % base_len], 1);
	return (chars);
}

ssize_t	put_uint_fd(unsigned int nbr, char *base, int fd)
{
	uintptr_t	base_len;
	ssize_t		chars;

	chars = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		chars = put_uint_fd(nbr / base_len, base, fd);
	chars += write(fd, &base[nbr % base_len], 1);
	return (chars);
}

ssize_t	put_int_fd(int nbr, char *base, int fd)
{
	ssize_t	base_len;
	ssize_t	chars;

	chars = 0;
	base_len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		chars = write(fd, "-2147483648", 11);
		return (chars);
	}
	if (nbr < 0)
	{
		chars = write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr >= base_len)
		chars += put_int_fd(nbr / base_len, base, fd);
	chars += write(fd, &base[nbr % base_len], 1);
	return (chars);
}
