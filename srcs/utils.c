/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:29:18 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/07 21:29:18 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit (-1);
}

void	check_map(char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1) 
		handle_error("open error");
	while (get_next_line(fd, &line))
		free(line)
	close(fd);
	if (line)
		free(line);
	else
		handle_error("Read error");
}

int	**mem_map(int width, int height)
{
	int	**map;
	int	i;

	map = malloc(sizeof(int *) * heigth);
	if (!map)
		handle_error("malloc error");
	i = 0;
	while (i++ < height)
	{
		map[i] = malloc(sizeof(int) * width)
		if (!map[i])
			handle_error("malloc error");
	}
	return (map);
}