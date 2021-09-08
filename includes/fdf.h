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

# include <stdio.h>
# include <stdlib.h>
# include "struct.h"

int		main(int ac, char **av);
void	handle_error(char *msg);
void	parse_map(t_fdf *info, char *file);
void	check_map(char *file);
int		**mem_map(int width, int height);

#endif