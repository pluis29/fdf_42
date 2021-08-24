/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:06:45 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/08/24 16:06:45 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parse_map(char *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	get_width(map);//largura
	get_height(map);//altura
	fd = open(map, O_RDONLY);
	if (fd == -1)
		handle_error("open error");
	imap->mtx = malloc(sizeof(int **) * imap->height)//malloc (ponteiro triplo)
	if (!imap->mtx)
		handle_error("malloc error");
	while (get_next_line(fd, &line))
	{
		imap->mtx[i] = malloc(sizeof(int *) * imap->width);
		if (!imap->mtx)
			handle_error("malloc error");
		fill_mtx(imap->mtx[i], line, imap->width);
		free(line);
	}
}

static void	get_width(char *map)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		handle_error("open error");
	get_next_line(fd, &line);
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i + 1] == ' '|| line[i + 1] == '\0')
			imap->width++;
		i++;
	}
	free(line);
	close(fd);
	if (fd == -1)
		handle_error("close error");
}

static void	get_height(char *map)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		handle_error("open error");
	while (get_next_line(fd, &line))
	{
		imap->height++;
		free(line);
	}
	free(line);
	close(fd);
	if (fd == -1)
		handle_error("close error");
}

static void	fill_mtx(int **mtx, char *line, int width)
{
	
}