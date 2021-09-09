/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:35:38 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/08 21:35:38 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_horizontal(t_fdf *fdf, int y, int z);
static void	draw_vertical(t_fdf *fdf, int y, int z);
static void	draw_lines(t_fdf *fdf);
static void	put_pixel(t_fdf *fdf, int y, int z, double uvector);

int	draw(t_fdf *fdf)
{
	int		z;
	int		y;

	z = 0;
	fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp,
		&fdf->image.size, &fdf->image.endian);
	while (z < fdf->map.height)
	{
		y = 0;
		while (y < fdf->map.width)
		{
			fdf->map.y0 = y;
			fdf->map.z0 = z;
			if (y + 1 < fdf->map.width)
				draw_horizontal(fdf, y ,z);
			if (z + 1 < fdf->map.height)
				draw_vertical(fdf, y ,z);
			y++;
		}
		z++;
	}
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0 ,0);
	text(fdf);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	return (0);
}

static void	draw_horizontal(t_fdf *fdf, int y, int z)
{
	int		yt;
	int		zt;

	yt = y - fdf->map.width / 2;
	zt = z - fdf->map.height / 2;
	fdf->map.y0 = fdf->map.angle_y * (yt - zt) * fdf->map.zoom;
	fdf->map.z0 = fdf->map.angle_z * (yt + zt) * fdf->map.zoom;
	fdf->map.z0 -= fdf->map.values[z][y] * fdf->map.x_value;
	fdf->map.y1 = fdf->map.angle_y * ((yt + 1) - zt) * fdf->map.zoom;
	fdf->map.z1 = fdf->map.angle_z * ((yt + 1) + zt) * fdf->map.zoom;
	fdf->map.z1 -= fdf->map.values[z][y + 1] * fdf->map.x_value;
	fdf->map.y0 += (WIN_WIDTH / 2) + fdf->map.coordinate_y;
	fdf->map.y1 += (WIN_WIDTH / 2) + fdf->map.coordinate_y;
	fdf->map.z0 += (WIN_HEIGHT / 2) + fdf->map.coordinate_z;
	fdf->map.z1 += (WIN_HEIGHT / 2) + fdf->map.coordinate_z;
	draw_lines(fdf);
}

static void	draw_vertical(t_fdf *fdf, int y, int z)
{
	int		yt;
	int		zt;

	yt = y - fdf->map.width / 2;
	zt = z - fdf->map.height / 2;
	fdf->map.y0 = fdf->map.angle_y * (yt - zt) * fdf->map.zoom;
	fdf->map.z0 = fdf->map.angle_z * (yt + zt) * fdf->map.zoom;
	fdf->map.z0 -= fdf->map.values[z][y] * fdf->map.x_value;
	fdf->map.y1 = fdf->map.angle_y * (yt - (zt + 1)) * fdf->map.zoom;
	fdf->map.z1 = fdf->map.angle_z * (yt + (zt + 1)) * fdf->map.zoom;
	fdf->map.z1 -= fdf->map.values[z + 1][y] * fdf->map.x_value;
	fdf->map.y0 += (WIN_WIDTH / 2) + fdf->map.coordinate_y;
	fdf->map.y1 += (WIN_WIDTH / 2) + fdf->map.coordinate_y;
	fdf->map.z0 += (WIN_HEIGHT / 2) + fdf->map.coordinate_z;
	fdf->map.z1 += (WIN_HEIGHT / 2) + fdf->map.coordinate_z;
	draw_lines(fdf);
}

static void	draw_lines(t_fdf *fdf)
{
	double	y;
	double	z;
	double	delta_y;
	double	delta_z;
	double	uvector;

	y = fdf->map.y0;
	z = fdf->map.z0;
	delta_y = fdf->map.y1 - fdf->map.y0;
	delta_z = fdf->map.z1 - fdf->map.z0;
	uvector = sqrt((pow(delta_y, 2)) + (pow(delta_z, 2)));
	delta_y /= uvector;
	delta_z /= uvector;
	
	while (uvector > 0)
	{
		put_pixel(fdf, y, z, uvector);
		y += delta_y;
		z += delta_z;
		uvector -= 1;
	}
}

static void	put_pixel(t_fdf *fdf, int y, int z, double uvector)
{
	int		pos;

	if ((y > 0 && z > 0) && (y < WIN_WIDTH && z < WIN_HEIGHT))
	{
		pos = (y * 4) + (z * WIN_WIDTH * 4);
		fdf->image.data[pos] = fdf->color.red + uvector;
		fdf->image.data[pos + 1] = fdf->color.green + uvector;
		fdf->image.data[pos + 2] = fdf->color.blue + uvector;
		fdf->image.data[pos + 3] = 0x7F + uvector;
	}
}
