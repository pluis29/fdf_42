/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:38:03 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/07 22:38:03 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_jump	cat_jump(int x, int y);
static void	bresenham(t_jump p1, t_jump p2, t_fdf *info);
void	set_pixel(t_jump p, int color, t_fdf *info);

void	draw(t_fdf *info, int clear)
{
	int	x;
	int y;

	if (clear)
	{
		mlx_clear_window(info->mlx, info->mlx_win);
		ft_bzero(info->img_data, WIN_WIDTH * WIN_HEIGHT * (info->bpp / 8));
	}
	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (x < info->width - 1)
				bresenham(cat_jump(x, y), cat_jump(x + 1, y), info);
			if (y < info->heigth - 1)
				bresenham(cat_jump(x, y), cat_jump(x, y + 1), info);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img_ptr, 0, 0);
	text(info);
}

static t_jump	cat_jump(int x, int y)
{
	t_jump jump;

	jump.x = x;
	jump.y = y;
	return(jump);
}

static void	bresenham(t_jump p1, t_jump p2, t_fdf *info)
{
	int	delta_X;
	int	delta_Y;
	int	error;
	int	error_check;

	magic(&p1, &p2, info);
	delta_X = ft_abs(p2.x - p1.x);
	delta_Y = ft_abs(p2.y - p1.y);
	error = delta_X - delta_Y;
	set_pixel(p1, info->color, info);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		ft_set_pixel(p1, info->color, info);
		error_check = error * 2;
		if (error_check > -delta_Y)
		{
			error -= delta_Y;
			p1.x += ft_nbrcmp(p2.x, p1.x);
		}
		if (error_check < delta_X)
		{
			error += delta_X;
			p1.y += ft_nbrcmp(p2.y, p1.y);
		}
	}
}

void	set_pixel(t_jump p, int color, t_fdf *info)
{
	int	pixel;

	if (p.y < WIN_WIDTH && p.x < WIN_HEIGHT)
	{
		pixel = (p.y * WIN_HEIGHT * 4) + (p.x * 4);
		color = mlx_get_color_value(info->mlx, color);
		if (p.x > 0 && pixel > 0
			&& pixel < WIN_WIDTH * WIN_HEIGHT * (info->bpp / 8))
		{
			info->img_data[pixel + 0] = (char)((color) & 0xFF);
			info->img_data[pixel + 1] = (char)((color >> 8) & 0xFF);
			info->img_data[pixel + 2] = (char)((color >> 16) & 0xFF);
			info->img_data[pixel + 3] = (char)((color >> 24));
		}
	}
	if (!info->mlx)
		destroy(info);
}