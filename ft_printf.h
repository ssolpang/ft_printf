/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:11:18 by jkwak             #+#    #+#             */
/*   Updated: 2022/04/05 21:54:19 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

/*main functions*/
int	ft_check_format_and_print(va_list ap, char format, int count);
int ft_just_print(char c, int count);
int	ft_printf(const char *format, ...);

/*check format and print functions*/
int	ft_char_format(va_list ap, int count);
int	ft_string_format(va_list ap, int count);
int	ft_decimal_integer_format(va_list ap, int count);
int	ft_unsigned_int_format(va_list ap, int count);
int	ft_pointer_format(va_list ap, int count);
int	ft_hexa_format(va_list ap, char c, int count);

/*utils*/
int		nbr_len_unsigned(unsigned int n);
char	*ft_itoa_unsigned(unsigned int n);
int		ft_count_digit(unsigned long long n);
char	*ft_itoa_hexa_base(unsigned long long n, int c);

#endif
