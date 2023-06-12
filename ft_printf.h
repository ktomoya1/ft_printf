/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:05:15 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/12 15:48:56 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

ssize_t	ft_putchar_fd_c(int c, int fd);
ssize_t	ft_putstr_fd_c(char *s, int fd);
int		ft_printf(const char *format, ...);

#endif
