/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:02:48 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/13 13:50:51 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	ssize_t	count;

	if (s == NULL)
		count = write(fd, "(null)", 6);
	else
		count = write(fd, s, ft_strlen(s));
	return (count);
}
