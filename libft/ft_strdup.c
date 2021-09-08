/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:29:07 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:15:14 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		cont1;
	int		cont2;
	char	*a;

	cont1 = 0;
	cont2 = 0;
	while (s[cont1])
		cont1++;
	a = (char *)malloc(sizeof(char) * (cont1 + 1));
	if (a == NULL)
		return (NULL);
	while (s[cont2])
	{
		a[cont2] = s[cont2];
		cont2++;
	}
	a[cont1] = '\0';
	return (a);
}

/*
	Copia uma string para uma outra variavel e retorna a string copiada.
	Obs: tem malloc.
*/