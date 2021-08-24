#include "fdf.h"

void	handle_error(char *msg, int fd)
{
	if (!fd)
		ft_putendl_fd(msg, fd);
	else
		perror(msg);
	exit(-1);
}