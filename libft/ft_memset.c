/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:04:02 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/05/15 14:04:02 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset (void *dest, int str, size_t n)
{
	unsigned char	*n_dest;
	size_t			i;

	i = 0;
	n_dest = (unsigned char *) dest;
	while (n-- > 0)
		n_dest[i++] = (unsigned char) str;
	return (dest);
}

/*
	Incrementa 'str' em 'dest' delimitado por 'n'. Retorna a string modificada.
*/