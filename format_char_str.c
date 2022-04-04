/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:28:51 by jkwak             #+#    #+#             */
/*   Updated: 2022/04/05 00:43:39 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_format(va_list ap)
{
	char	s;

	s = va_arg(ap, int);
	ft_putchar_fd(s, 1);
}

void	ft_string_format(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr_fd(s, 1);
}
