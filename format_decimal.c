/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:32:48 by jkwak             #+#    #+#             */
/*   Updated: 2022/04/05 16:13:56 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal_integer_format(va_list ap, int count)
{
	int		n;
	char	*s;

	n = va_arg(ap, int);
	s = ft_itoa(n);
	count += ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (count);
}

int	ft_unsigned_int_format(va_list ap, int count)
{
	unsigned int	n;
	char			*s;

	n = va_arg(ap, unsigned int);
	s = ft_itoa_unsigned(n);
	count += ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (count);
}
