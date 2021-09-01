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
	malloc_mtz(imap);
	fd = open(map, O_RDONLY);
	if (!fd)
		handle_error("open error");
	imap->mtz = (int **)malloc(sizeof(int *) * imap->height);
	if (!imap->mtz)
		handle_error("malloc error");
	while(i++ < imap->height)
	{
		imap->mtz[i] = (int *)malloc(sizeof(int) * imap->width);
		if (!imap->mtz[i])
			handle_error("malloc error");
	}
	i = 0;
	while (get_next_line(fd, &line)
	{
		set_mtz(imap, line, imap->mtz[i])
		i++;
		imap->info++;
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

static void	set_mtz(t_imap *imap, char *line, int **mtz)
{
	char	*split;
	char	*tmp;
	int		i;

	i = 0;
	split = st_split(line, ' ');//splitou a linha
	while (split[i++] && i < imap->width)
	{
		tmp[i] = filter(split[i]);
		imap->mtz[imap->info] == ft_strjoin(imap->mtz[imap->info], split[i]);
	}
}
