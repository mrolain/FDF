/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 03:28:32 by mrolain           #+#    #+#             */
/*   Updated: 2024/09/09 15:39:58 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_line(int map)
{
	char	*buffer;
	int		lines;
	
	lines = 0;
	buffer = malloc(sizeof(char) * 2);
	while (read(map, buffer, 1) != 0)
	{
		if (buffer[0] == '\n')
			lines++;
	}
	free(buffer);
	close(map);
	return (lines);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw(int button, int x, int y, void *param)
{
    t_vars *vars = (t_vars *)param;

    if (button == 1)
	{
        my_mlx_pixel_put(&vars->img, x, y, 0xFFF0FF00);
		my_mlx_pixel_put(&vars->img, x + 1, y, 0xFFF0FF00);
		my_mlx_pixel_put(&vars->img, x, y + 1, 0xFFF0FF00);
		my_mlx_pixel_put(&vars->img, x + 1, y + 1, 0xFFF0FF00);
		my_mlx_pixel_put(&vars->img, x - 1, y, 0xFFF0FF00);
		my_mlx_pixel_put(&vars->img, x - 1, y - 1, 0xFFF0FF00);
		my_mlx_pixel_put(&vars->img, x + 1, y - 1, 0xFFF0FF00);
		my_mlx_pixel_put(&vars->img, x - 1, y + 1, 0xFFF0FF00);
		my_mlx_pixel_put(&vars->img, x, y - 1, 0xFFF0FF00);
	}
    if (button == 3)
	{
        my_mlx_pixel_put(&vars->img, x, y, 0x000000);
		my_mlx_pixel_put(&vars->img, x + 1, y, 0x000000);
		my_mlx_pixel_put(&vars->img, x, y + 1, 0x000000);
		my_mlx_pixel_put(&vars->img, x + 1, y + 1, 0x000000);
		my_mlx_pixel_put(&vars->img, x - 1, y, 0x000000);
		my_mlx_pixel_put(&vars->img, x - 1, y - 1, 0x000000);
		my_mlx_pixel_put(&vars->img, x + 1, y - 1, 0x000000);
		my_mlx_pixel_put(&vars->img, x - 1, y + 1, 0x000000);
		my_mlx_pixel_put(&vars->img, x, y - 1, 0x000000);
	}
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);

    return (0);
}

void	place_points(void *param, int map, int x, int y, char **argv)
{
	t_vars	*vars = (t_vars *)param;
	char	**array;
	int		i;
	int 	lines;
	
	i = 0;
	lines = count_line(map);
	map = open(argv[1], O_RDONLY);
	while (y / 15 != lines)
	{
		array = ft_split(get_next_line(map), ' ');
		while (array[i])
		{
			if (ft_atoi(array[i]) == 0)
			{
				my_mlx_pixel_put(&vars->img, x, y, 0xFFFFFF);
				x += 15;
			}
			else
			{
				my_mlx_pixel_put(&vars->img, x, y, 0xFF0000);
				x += 15;
			}
			i++;
		}
		x = 0;
		i = 0;
		y += 15;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		map;
	unsigned int	x;
	unsigned int	y;

	(void)argc;
	x = 1400;
	y = 800;
	map = open(argv[1], O_RDONLY);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "FDF");
	vars.img.img = mlx_new_image(vars.mlx, x, y);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								&vars.img.endian);

	place_points(&vars, map, 0, 0, argv);
	mlx_hook(vars.win, 2, 1L<<0, escclose, &vars);
	mlx_hook(vars.win, 17, 1L<<2, xclose, &vars);
	mlx_mouse_hook(vars.win, draw, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, x, y);
	mlx_loop(vars.mlx);
	exit(0);
}