/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:48:18 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:16:38 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cont1;
	size_t	cont2;

	cont1 = 0;
	cont2 = 0;
	if (*little == '\0')
		return ((char *)big);
	while (cont1 < len && big[cont1])
	{
		while (big[cont1 + cont2] == little[cont2]
			&& cont1 + cont2 < len && little[cont2] != '\0')
			cont2++;
		if (little[cont2] == '\0')
			return ((char *)big + cont1);
		cont1++;
		cont2 = 0;
	}
	return (NULL);
}

/*
	Se 'little' existir em 'big' retorna a a partir da ocorrencia adiante.

	Percorre o 'big' e ao mesmo tempo em cada posição compara para ver se o
caracter é igual ao 'little' se for ele entra no segundo while. Este while
vai comparar as posições futuras de 'big' para saber se 'little' existe ate o
fim da string e que nao terminou o delimitador 'len'. Obs: precisa garantir que
o 'little' foi achado por completo em 'big'.
*/