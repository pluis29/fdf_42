/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:58:58 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/08 19:58:58 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	reset_map(t_fdf *fdf);
static int	keys(int keycode, t_fdf *fdf);
static void	random_color(t_fdf *fdf);
void    putstr_mlx(char *str, int start, t_fdf *fdf);

int main(int ac, char **av)
{
	t_fdf *fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		handle_error("Malloc failed");
	if (ac != 2)
		handle_error("Usage invalid: ./fdf ./maps/...");
	parse(av[1], fdf);
	reset_map(fdf);
	fdf->mlx.init = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, 
		"42_FDF");
	mlx_hook(fdf->mlx.win, 2, 3, keys, fdf);
	mlx_loop_hook(fdf->mlx.init, draw, fdf);
	mlx_loop(fdf->mlx.init);	
	destroy((void **)fdf->map.values);
	free(fdf);
	return (0);
}

static void	reset_map(t_fdf *fdf)
{
	fdf->map.coordinate_z = 0;
	fdf->map.coordinate_y = 0;
	fdf->map.x_value = 1.00;
	fdf->map.angle = M_PI / 3;
	fdf->map.angle_y = cos(M_PI / 3);
	fdf->map.angle_z = fdf->map.angle_y * sin(M_PI / 6);
	if (fdf->map.width > fdf->map.height)
		fdf->map.zoom = ceil((WIN_WIDTH / fdf->map.width) + MAGIC_ZOOM);
	else
		fdf->map.zoom = ceil((WIN_HEIGHT / fdf->map.height) + MAGIC_ZOOM);
	fdf->map.isometric = 1;
	fdf->color.red = 0x4F;
	fdf->color.green = 0x4F;
	fdf->color.blue = 0x4F;
}

static int	keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		destroy((void **)fdf);
	else if (keycode == KEY_ABNT_R)
		reset_map(fdf);
	else if (keycode == KEY_ABNT_T)
		random_color(fdf);
	else if (keycode == KEY_ABNT_W)
		fdf->map.coordinate_z -= 1;
	else if (keycode == KEY_ABNT_S)
		fdf->map.coordinate_z += 1;
	else if (keycode == KEY_ABNT_D)
		fdf->map.coordinate_y += 1;
	else if (keycode == KEY_ABNT_A)
		fdf->map.coordinate_y -= 1;
	else if (keycode == KEY_ABNT_Q)
		fdf->map.angle += M_PI / 16;
	else if (keycode == KEY_ABNT_E)
		fdf->map.angle += M_PI / 16;
	else if (keycode == KEY_ABNT_J)
		fdf->map.zoom += 1;
	else if ((keycode == KEY_ABNT_K) && (fdf->map.zoom > MAX_ZOOM))
		fdf->map.zoom -= 1;
	else if ((keycode == KEY_ABNT_U) && (fdf->map.x_value < MAX_X))
		fdf->map.x_value += 0.25;
	else if ((keycode == KEY_ABNT_I) && (fdf->map.x_value > -MAX_X))
		fdf->map.x_value -= 0.25;
	else if (keycode == KEY_SPACE)
		key_space(fdf);
	return (0);
}


static void	random_color(t_fdf *fdf)
{
	fdf->color.red = (rand() % 0x7F);
	fdf->color.green = (rand() % 0x7F);
	fdf->color.blue = (rand() % 0x7F);
}

void    putstr_mlx(char *str, int start, t_fdf *fdf)
{
    static int    height;

    if (!height || start)
        height = T_OFFSET;
    height += T_HEIGHT;
    mlx_string_put(fdf->mlx.init, fdf->mlx.win, T_OFFSET, height, T_COLOR, str);
}