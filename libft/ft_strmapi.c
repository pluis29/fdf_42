/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:46:13 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:22:02 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*ns;

	i = 0;
	if (s == NULL)
		return (NULL);
	ns = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ns == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ns[i] = f(i, s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

/*
	Percorre uma string mudando caracter por caracter de acordo com a função
passada no parametro.
*/