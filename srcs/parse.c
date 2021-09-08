/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:35:06 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/07 21:35:06 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_map(int *ideal, char *line);
static int	get_heigth(char *file);
static int	get_width(char *file);

void	parse_map(t_fdf *info, char *file)
{
	char	*line;
	int		fd;
	int		i;

	check_map(file);
	info->heigth = get_heigth(file);
	info->width = get_width(file);
	fd = open(file, O_RDONLY);
	info->map = mem_map(info->width, info->heigth);
	i = 0;
	while (get_next_line(fd, &line))
	{
		set_map(info->map[i], line);
		free(line);
		i++;
	}
}

static void	set_map(int *ideal, char *line)
{
	char	**split;
	char	i;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i++])
	{
		ideal[i] = ft_atoi(ideal[i]);
		free(split[i]);
	}
	free(split);
}

static int	get_heigth(char *file)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1) 
		handle_error("open error");

	i = 0;
	while (get_next_line(fd, &line));
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	return (i);
}

static int	get_width(char *file)
{
	char	*line;
	int		width;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1) 
		handle_error("open error");
	i = 0;
	width = 0;
	get_next_line(fd, &line);
	if (*line == '\0')
		handle_error("invalid map");
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
		i++;
	}
	free(line);
	close(fd);
	return (width);
}