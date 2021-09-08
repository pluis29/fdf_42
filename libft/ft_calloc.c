/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:47:31 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 22:21:16 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nn;

	nn = malloc(nmemb * size);
	if (nn == NULL)
		return (NULL);
	ft_bzero(nn, nmemb * size);
	return (nn);
}

/*
	aloca memoria mas preenche de 0 nao deixando qualquer lixo na memoria

	a alocacao é parecida com malloc nmemb seria quantas vezes de sizeof de algo
o size seria o sizeof().
	o ft_bzero adiciona os 0 que queremos na string alocada com o tamanho da
alocacao.
*/
