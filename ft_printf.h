/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:11:18 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/25 23:02:11 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

//utils
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);

#endif
