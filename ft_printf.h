/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:05:15 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/14 17:05:06 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <inttypes.h>
# include <limits.h>

ssize_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
ssize_t	ft_putchar_fd(int c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
ssize_t	put_ptr_fd(uintptr_t address, char *base, int fd);
ssize_t	put_int_fd(int nbr, char *base, int fd);
ssize_t	put_uint_fd(unsigned int nbr, char *base, int fd);
int		ft_printf(const char *format, ...);

#endif
