/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:36:37 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/30 00:29:37 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

size_t	ft_putnbr_base(ssize_t nbr, char *base, const char type);
size_t	ft_putstr(const char *s);
size_t	ft_putchar(const char c);
char	*ft_strchr(const char *str, int c);

#endif
