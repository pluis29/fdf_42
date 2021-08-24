#include "fdf_h"

static int	get_width(char *filename)
{
	int		i;
	int		fd;
	int		width;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("open error", 1);
	width = 0;
	get_next_line(fd, &line);
	while(line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
		i++
	}
	free(line);
	if(close(fd) == -1)
		handle_error("close error", 1);
	return (width);
}

static int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("open error", 1);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		handle_error("close error", 1);
	return (height);
}

static void fill_table(int **array, char *line, int width)
{
	char	**cnum;
	int		x;
	int		y;

	num = ft_split(line, ' ');
	x = -1
	while (num[++x] && x < width)
	{
		array[x] = malloc(sizeof(int) * 2);
		if (!array[x])
			handle_error("malloc error", 1);
		array[x][0] = ft_atoi(cnum[x])
		y = 0;
		while(cnum[x][y] & cnum[x][y] != ',')
			y++;
		if (xnum[x][y] == ',')
			array[x][1] = ft_atoi_base(&cnum[x][++y], "0123456789ABCDEF");
		else
			array[x][1] = -1;
		free(cnum[x]);
	}
	//if (x != width || cnum[i])
	//	handle_error("error: fdf file has irregular width", 1)
	free(cnum);
}


void	parse_map(char *filename, t_map *imap)
{
	int		i;
	int		fd;	
	char	*line;

	imap->width = get_width(filename);
	imap->height = get_height(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("open error", 1);
	imap->array = malloc(sizeof(int **) * map->height);
	if (!map->array)
		handle_error("malloc_error", 1);
	i = -1;
	while (get_next_line(fd, &line) > 0)
	{
		imap->array[++i] = malloc(sizeof(int *) * imap->width);
		if(!imap->array[i])
			handle_error("malloc error", 1);
		fill_table(map->array[i], line, imap->width);
		free(line)
	}
	free(line)
	//!
	if (close == -1)
		handle_error("close error", 1);
}