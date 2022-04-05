/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:51:02 by jkwak             #+#    #+#             */
/*   Updated: 2022/01/07 18:37:34 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && *(haystack + i))
	{
		j = 0;
		while ((*(haystack + i + j) == *(needle + j))
			&& *(needle + j) && ((i + j) < len))
			j++;
		if (!*(needle + j))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
