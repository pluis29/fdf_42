/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:29:18 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/07 21:29:18 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit (-1);
}

void	destroy(t_fdf *info)
{
	mlx_destroy_image(info->mlx, info->img_ptr);
	mlx_clear_window(info->mlx, info->mlx_win);
	mlx_destroy_window(info->mlx, info->mlx_win);
	ft_clear_map(info->map, info);
	free(info);
	exit(0);
}

int	**mem_map(int width, int height)
{
	int	**map;
	int	i;

	map = malloc(sizeof(int *) * heigth);
	if (!map)
		handle_error("malloc error");
	i = 0;
	while (i++ < height)
	{
		map[i] = malloc(sizeof(int) * width)
		if (!map[i])
			handle_error("malloc error");
	}
	return (map);
}

void	putstr_mlx(char *str, int start, t_fdf *info)
{
	static int	height;

	if (!height || start)
		height = T_OFFSET;
	height += T_HEIGHT;
	mlx_string_put(info->mlx, info->mlx_win, T_OFFSET, height, T_COLOR, str);
}

void	text(t_fdf *info)
{
	putstr_mlx("Controls:", 1, info);
	putstr_mlx("W/A/S/D - Move", 0, info);
	putstr_mlx("Q/E - Rotate", 0, info);
	putstr_mlx("Z/X - Scaling", 0, info);
	putstr_mlx("F/G - Shift Heights", 0, info);
	putstr_mlx("I/P - Change projection", 0, info);
	putstr_mlx("ESC - Exit", 0, info);
}
