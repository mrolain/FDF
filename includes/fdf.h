/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:29:54 by mrolain           #+#    #+#             */
/*   Updated: 2024/09/09 15:06:59 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"

typedef struct	coords {
	int	x;
	int	y;
	int	z;
}		coords;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}				t_vars;

int	xclose(t_vars *vars);
int	escclose(int keycode, t_vars *vars);
int	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif