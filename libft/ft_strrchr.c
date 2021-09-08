/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:18:23 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:16:45 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	found;

	i = 0;
	found = (char) c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == found)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*
	Procura a ultima ocorrencia de 'c' na string e retorna de lá adiante.

	Pega o tamanho da string e vai de tras para frente '<-' pois assim se achar
'c' em 's' ja sabe que é a ultima ocorrencia.
*/