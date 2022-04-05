/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:29:23 by jkwak             #+#    #+#             */
/*   Updated: 2022/01/10 23:00:24 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_over(int sign, unsigned long long int nbr)
{
	if (nbr > 9223372036854775806 && sign == 1)
		return (-1);
	if (nbr > 9223372036854775807 && sign == -1)
		return (0);
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	nbr;

	i = 0;
	while (((*(str + i) >= 9) && (*(str + i) <= 13))
		|| (*(str + i) == 32))
		i++;
	sign = 1;
	if ((*(str + i) == '+') || (*(str + i) == '-'))
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	nbr = 0;
	while ((*(str + i) >= '0') && (*(str + i) <= '9'))
	{
		nbr = (nbr * 10) + *(str + i) - '0';
		i++;
	}
	nbr = check_over(sign, nbr);
	return (sign * nbr);
}
