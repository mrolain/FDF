/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:33:02 by mrolain           #+#    #+#             */
/*   Updated: 2024/08/05 12:07:13 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
