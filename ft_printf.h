/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:05:15 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/13 21:15:22 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

ssize_t	ft_strlen(const char *s);
ssize_t	ft_putchar_fd(int c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
ssize_t	put_address_fd(uintptr_t address, char *base, int fd);
ssize_t	ft_putint_fd(int nbr, char *base, int fd);
int		ft_printf(const char *format, ...);

#endif
