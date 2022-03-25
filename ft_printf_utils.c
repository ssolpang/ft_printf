/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:57:35 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/25 22:59:22 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		s1_len;
	int		i;

	s1_len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (result == 0)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(result + i) = *(s1 + i);
		i++;
	}
	*(result + i) = 0;
	return (result);
}

int	nbr_len(long long int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	nbr_sign(long long int n)
{
	if (n > 0)
		return (1);
	else
		return (-1);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				len;
	int				sign;
	long long int	nb;

	nb = (long long int)n;
	if (nb == 0)
		return (ft_strdup("0"));
	len = nbr_len(nb);
	sign = nbr_sign(nb);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	*(nbr + len--) = 0;
	if (nb < 0)
		nb = -nb;
	while (len >= 0)
	{
		*(nbr + len) = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (sign < 0)
		*(nbr + 0) = '-';
	return (nbr);
}
