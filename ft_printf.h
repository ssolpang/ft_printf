/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:11:18 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/31 21:15:20 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

/*main functions*/
void	ft_check_format_and_print(va_list ap, char format);
int		ft_printf(const char *format, ...);

/*check format and print functions*/
void	ft_char_format(va_list ap);
void	ft_string_format(va_list ap);
void	ft_decimal_integer_format(va_list ap);
void	ft_unsigned_int_format(va_list ap);
void	ft_pointer_format(va_list ap);
void	ft_hexa_format(va_list ap, char c);

/*utils*/
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_hexa_base(size_t n, int c);

#endif
