/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:11:18 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/29 16:09:07 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

//format functions
void	ft_char_format(va_list ap);
void	ft_string_format(va_list ap);
void	ft_decimal_integer_format(va_list ap);
void	ft_unsigned_int_format(va_list ap);
void	ft_pointer_format(va_list ap);
void	ft_hexa_format(va_list ap, char c);

//utils
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
char    *ft_itoa_unsigned(unsigned int n);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size);
char	*ft_itoa_hexa_base(size_t n, int c);

#endif
