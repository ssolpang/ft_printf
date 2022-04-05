/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:28:51 by jkwak             #+#    #+#             */
/*   Updated: 2022/04/05 21:36:16 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_format(va_list ap, int count)
{
	char	s;

	s = va_arg(ap, int);
	ft_putchar_fd(s, 1);
	return (count + 1);
}

int	ft_string_format(va_list ap, int count)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
		return (count);
	}
	count += ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (count);
}
