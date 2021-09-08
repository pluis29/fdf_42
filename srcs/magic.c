/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:42:51 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/08 14:42:51 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	scale(t_jump *p1, t_jump *p2, int scale);
static void	shifting(t_jump *p1, t_jump *p2, int x_val, int y_val);
static void	proj_iso(t_jump *p, float angle, int z);
static void	proj_def(t_jump *p, int z);

void	magic(t_jump *p1, t_jump *p2, t_fdf *info)
{
	int	shift_z;
	int	z1;
	int	z2;

	info->color = get_color(p1, p2, info);
	shift_z = info->shift_z;
	z1 = info->map[p1->y][p1->x] * shift_z;
	z2 = info->map[p2->y][p2->x] * shift_z;
	scale(p1, p2, info->scale);
	if (info->proj = 0)
	{
		proj_def(p1, z1);
		proj_def(p2, z2);
	}
	else
	{
		proj_iso(p1, info->angle, z1);
		proj_iso(p2, info->angle, z2);
	}
	shifting(p1, p2, info->shift_x, info->shift_y);
}

static void	scale(t_jump *p1, t_jump *p2, int scale)
{
	p1->x *= scale;
	p1->y *= scale;
	p2->x *= scale;
	p2->y *= scale;
}

static void	shifting(t_jump *p1, t_jump *p2, int x_val, int y_val)
{
	p1->x += x_val;
	p1->y += y_val;
	p2->x += x_val;
	p2->y += y_val;
}

static void	proj_iso(t_jump *p, float angle, int z)
{
	p->x = (int)round((p->x - p->y) * cos(angle));
	p->y = (int)round((p->x + p->y) * sin(angle) - z);
}

static void	proj_def(t_jump *p, int z)
{
	if (z != 0)
	{
		p->x = (int)round((p->x) * cos(M_PI / 4));
		p->y = (int)round((p->y) * sin(M_PI / 4));
	}
}
