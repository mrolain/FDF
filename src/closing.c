/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 03:20:20 by mrolain           #+#    #+#             */
/*   Updated: 2024/07/24 03:25:17 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	xclose(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	escclose(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		xclose(vars);
	return (0);
}