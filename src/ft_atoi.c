/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:55:03 by mrolain           #+#    #+#             */
/*   Updated: 2024/07/24 05:39:23 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_atoi(const char *nptr)
{
	int	value;
	int	i;
	int	sign;

	value = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value *= 10;
		value += (nptr[i] - 48);
		i++;
	}
	value *= sign;
	return (value);
}

// int	main()
// {
// 	printf("%d\n", ft_atoi("   -4886"));
// 	return (0);
// }
