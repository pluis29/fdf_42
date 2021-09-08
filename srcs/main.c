/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:28:06 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/07 21:28:06 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_info(t_fdf *info)
{
	info->proj = 1;
	if (info->width > 9)
		info->scale = (int) rintf(55 / rintf((float) info->width / 10));
	else
		info->scale = 150;
	info->angle = M_PI / 3;
	info->shift_x = WIN_HEIGHT / 3;
	info->shift_y = WIN_WIDTH / 3;
	info->shift_z = 1;
	info->mlx = mlx_init();
	if (!info->mlx)
		handle_error("error in mlx start");
	info->mlx_win = mlx_new_window(info->mlx, WIN_HEIGHT, WIN_WIDTH, "42_FDF");
	if (!info->mlx_win)
		handle_error("error in mlx window");
	info->bpp = 32;
	info->size_line = WIN_HEIGHT * 4;
	info->endian = 1;
	info->img_ptr = mlx_new_image(info->mlx, WIN_HEIGHT, WIN_WIDTH);
	info->img_data = mlx_get_data_addr(info->img_ptr, &info->bpp,
		&info->size_line, &info->endian);
}

int	exit_button(t_fdf *info)
{
	mlx_clear_window(info->mlx, info->mlx_win);
	mlx_destroy_window(info->mlx, info->mlx_win);
	ft_clear_map(info->map, info);
	free(info);
	exit(0);
}

int	key_mlx(int keycode, t_fdf *info)
{
	int	key_exists;

	key_exists = controls(keycode, info);
	if (key_exists)
		draw(info, 1);
	return (0);
}

int	get_color(t_jump *p1, t_jump *p2, t_fdf *info)
{
	int	z1;
	int	z2;

	z1 = info->map[p1->y][p1->x];
	z2 = info->map[p2->y][p2->x];
	if (z1 > z2)
		return (0xff0000);
	if (z1 < z2)
		return (0x0000ff);
	if (z1 > 0)
		return (0x6f00ff);
	if (z1 < 0)
		return (0x00e5ff);
	return (0xffffff);
}

int	main(int ac, char **av)
{
	t_fdf *info;

	if (ac != 2)
		handle_error("Usage invalid: ./fdf 'map'");
	info = malloc(sizeof(t_fdf));
	if (!info)
		handle_error("malloc error");
	set_info(info);
	parse_map(info, av[1]);
	draw(data, 0);
	mlx_do_key_autorepeaton(info->mlx);
	mlx_hook(info->mlx_win, 17, 1L << 17, exit_button, info);
	mlx_key_hook(info->mlx_win, key_mlx, info);
	mlx_loop(info->mlx);
	return (0);
}