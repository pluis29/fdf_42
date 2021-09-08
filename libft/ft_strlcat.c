/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:31:38 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:15:43 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	i = 0;
	if (len_dst < size)
	{
		while ((i + len_dst) < (size - 1) && src[i])
		{
			dst[i + len_dst] = src[i];
			i++;
		}
		dst[i + len_dst] = '\0';
	}
	return (len_dst + ft_strlen(src));
}

/*
	Concatena 'src' em 'dest' delimitado por 'size' e retorna o tamanho da 
criação.

	Concatena 'src' em 'dest' desde que 'dest' nao seja maior q 'size'. Retorna
o tamanho da string q tentou criar se o if for verdadeiro retorna o tamanho e a
concatenacao acontece se nao so retorna o tamanho de 'dest' limitado por 'size'
+ o tamanho de 'src' e nao faz concatenação.
	Primeiro while pega o tamanho de dest sem estorar o delimitador de 'size'.
*/