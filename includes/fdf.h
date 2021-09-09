/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:53:25 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/08 19:53:25 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

# include "../get_next_line/get_next_line.h" 
# include "../libft/libft.h"
# include "shortcuts.h"
# include "struct.h"

# define MAX_X			(10)
# define MAX_ZOOM		(5)
# define MAGIC_ZOOM		(2)
# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)

void	parse(char *file, t_fdf *fdf);
void	handle_error(char *message);
void	check(int *cols, int *rows, int *len);
void	destroy(void **str);
void	key_space(t_fdf *fdf);
int		main(int ac, char **av);
void	draw(t_fdf *fdf);

#endif
