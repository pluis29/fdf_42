/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:38:20 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/05/17 13:38:20 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ns;
	size_t			i;

	i = 0;
	ns = s;
	while (i++ < len)
		*ns++ = 0;
}

/*
adicional 0 ou NULL na string ate o tamanho determinado.
*/