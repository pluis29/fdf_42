/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:05:12 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/08 16:05:12 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
static int	controls_system(int keycode, t_fdf *info);
static int	controls_transforms(int keycode, t_fdf *info);
static int	controls_move(int keycode, t_fdf *info);
static int	controls_proj(int keycode, t_fdf *info);

int	controls(int keycode, t_fdf *info)
{
	int	key_exists;

	key_exists = 0;
	key_exists |= controls_system(keycode, info);
	key_exists |= controls_transforms(keycode, info);
	key_exists |= controls_move(keycode, info);
	key_exists |= controls_proj(keycode, info);
	return (key_exists);
}

static int	controls_system(int keycode, t_fdf *info)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_EXIT && ++finded)
		destroy(info);
	return (finded);
}

static int	controls_transforms(int keycode, t_fdf *info)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_SCALE_PLUS && ++finded)
		info->scale++;
	if (keycode == KEY_SCALE_MINUS && ++finded)
		info->scale--;
	if (keycode == KEY_ROTATE_LEFT && ++finded)
		info->angle += M_PI / 16;
	if (keycode == KEY_ROTATE_RIGHT && ++finded)
		info->angle -= M_PI / 16;
	if (keycode == KEY_HEIGHT_PLUS && ++finded)
		info->shift_z++;
	if (keycode == KEY_HEIGHT_MINUS && ++finded)
		info->shift_z--;
	return (finded);
}

static int	controls_move(int keycode, t_fdf *info)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_UP && ++finded)
		info->shift_y -= 50;
	if (keycode == KEY_DOWN && ++finded)
		info->shift_y += 50;
	if (keycode == KEY_RIGHT && ++finded)
		info->shift_x += 50;
	if (keycode == KEY_LEFT && ++finded)
		info->shift_x -= 50;
	return (finded);
}

static int	controls_proj(int keycode, t_fdf *info)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_PROJ_DEF && ++finded)
		info->proj = 0;
	if (keycode == KEY_PROJ_ISO && ++finded)
		info->proj = 1;
	return (finded);
}
