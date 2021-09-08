/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:16:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/05/17 13:16:21 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*s_dest;
	const unsigned char	*s_src;

	s_dest = (unsigned char *)dest;
	s_src = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (dest < src)
		ft_memcpy(s_dest, s_src, n);
	else
		while (n--)
			s_dest[n] = s_src[n];
	return (s_dest);
}

/*
	Sobrescreve o 'src' em 'dest' delimitado por 'n' mas trata o erro de overlap

	Cast nos parametros pois sao void. Se dest > src, para evitar perder o
conteudo de src ou overlap que seria:  [-----src-----]
												[------dest-----]
quando houver a copia se for no sentido -> o final de src se perde por overlap
se for <- nada se perde e nao ha overlap.
*/