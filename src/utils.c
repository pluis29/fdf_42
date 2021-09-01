/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:02:30 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/08/24 16:02:30 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit (-1);
}

void	malloc_mtz(t_imap *imap)
{
	int		i;

	i = 0;
	imap->mtz = (int **)malloc(sizeof(int *) * imap->height);
	if (!imap->mtz)
		handle_error("Malloc error");
	while(i < imap->height)
	{
		impap->mtz[i] = (int *)malloc(sizeof(int) * imap->width);
		if(!imap->mtz[i])
			handle_error("Malloc error");
		i++;
	}
}


char	*filter(char *target)
{
	int		i;
	char	*done
	i = 0;
	while (target[i++] != '\0')
	{
		if (target[i] == ',' && !ft_isnumber(target[i])
		{
			done[i] = '\0';
			return (done);
		}
		done[i] = malloc(sizeof(char) * 3);
		if (!target[i])
			handle_error("malloc error");
		done[i] = target[i];
	}
	done[i] = '\0';
	return(done);
}