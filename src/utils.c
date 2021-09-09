/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:04:35 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/08 20:04:35 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_error(char *message)
{
	ft_putendl_fd(message, 1);
	exit(0);
}

void	check(int *cols, int *rows, int *len)
{
	if (*len > *cols)
		*cols = *len;
	if (*cols == *len)
		*rows += 1;
	else
		handle_error("Not a valid file");
}

void	destroy(void **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i]);
}

void	key_space(t_fdf *fdf)
{
	if (fdf->map.isometric++ % 2)
		fdf->map.angle_z *= 0.2;
	else
		fdf->map.angle_z *= 5;
}

void	text(t_fdf *fdf)
{
	putstr_mlx("Controls:", 1, fdf);
    putstr_mlx("W/A/S/D - Move", 0, fdf);
    putstr_mlx("J/K - Zoom", 0, fdf);
    putstr_mlx("U/I - Shift Heights", 0, fdf);
    putstr_mlx("Space - Change projection", 0, fdf);
    putstr_mlx("ESC - Exit", 0, fdf);
}