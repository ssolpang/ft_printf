/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 19:17:26 by jkwak             #+#    #+#             */
/*   Updated: 2022/01/10 22:51:09 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	len;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	len -= 1;
	while (len >= 0)
	{
		(*f)(len, (s + len));
		len--;
	}
}
