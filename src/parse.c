/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:18:57 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/08 20:18:57 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_map(t_fdf *fdf, int y, int z, char *line);
static void	get_info(t_fdf *fdf, char *file);
static int get_values(char *line);

void	parse(char *file, t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		y;
	int		z;

	get_info(fdf, file);
	fd = open(file, O_RDONLY);
	if (!fd)
		handle_error("Open error");
	fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height);
	if (!fdf->map.values)
		handle_error("Malloc error");
	y = 0;
	z = 0;
	while (get_next_line(fd, &line) && z != fdf->map.height)
	{
		fdf->map.values[z] = (int *)malloc(sizeof(int *) * fdf->map.width);
		if (!fdf->map.values[z])
			handle_error("Malloc error");
		set_map(fdf, y, z, line);
		y = 0;
		z++;
		free(line);
	}
	if (close(fd) < 0)
		handle_error("Close error");
}

static void	set_map(t_fdf *fdf, int y, int z, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (split)
	{
		i = 0;
		while (split[i] && (y != fdf->map.width))
		{
			fdf->map.values[z][y] = ft_atoi(split[i++]);
			y++;
		}
		free(split);
	}
}

static void	get_info(t_fdf *fdf, char *file)
{
	char	*line;
	int		fd;
	int		len;
	int		cols;
	int		rows;

	rows = 0;
	cols = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_error("Open error");
	while (get_next_line(fd, &line))
	{
		if (*line == '\0')
			break ;
		len = get_values(line);
		check(&cols, &rows, &len);
		free(line);
	}
	if (close(fd) < 0)
		handle_error("Close error");
	fdf->map.width = cols;
	fdf->map.height = rows;
}

static int get_values(char *line)
{
	int		len;

	len = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			len += 1;
			while (ft_isdigit(*line))
				line += 1;
		}
		//else if (*line == ' ' || *line == '-')
		//	handle_error("Invalid characters or read error");
		line += 1;
	}
	return (len);
}
