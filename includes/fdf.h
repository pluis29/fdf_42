/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:25:51 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/07 21:25:51 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include "struct.h"
# include "controls.h"

# define WIN_HEIGHT 1280
# define WIN_WIDTH 720
# define T_OFFSET 50
# define T_HEIGHT 17
# define T_COLOR 0xff9415

void	handle_error(char *msg);
void	parse_map(t_fdf *info, char *file);
void	draw(t_fdf *info, int clear)
void	magic(t_jump *p1, t_jump *p2, t_fdf *info)
void	text(t_fdf *info)
void	putstr_mlx(char *str, int start, t_fdf *info)
void	destroy(t_fdf *info)
int		main(int ac, char **av);
int		**mem_map(int width, int height);
int		get_color(t_jump *p1, t_jump *p2, t_fdf *info)
int		key_mlx(int keycode, t_fdf *info)
int		exit_button(t_fdf *info)
int		controls(int keycode, t_fdf *info)

#endif