/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:18:37 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:17:06 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	nlen;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	nlen = ft_strlen(s + start);
	if (nlen < len)
		len = nlen;
	ns = (char *)malloc(sizeof(char) * (len + 1));
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s + start, len + 1);
	return (ns);
}

/*
	Faz uma copia de 's' com delimitador de incio e ate onde vai copiar.

	Se 's' é uma string em que o tamanho dela nao seja a posicao de 'start' no
qual queremos começar a fazer a copia retornamos uma string vazia. Usamos
strdup pois precisamos retornar uma outra variavel.
	Terceiro if quer dizer que se o tamanho de 's' a partir do 'start' for menor
que o tamanho de 'len', significa q temos uma string 'menor doq o delimitador
'len'' entao o tamanho de s+start é passado para o valor de 'len' e a alocacao
é feito de maneira q nao haja uso de memoria indevido.
	Se essa condicao nao for verdade o len continua sendo ele mesmo sem
modificao. E procede com a copia com o strlcpy retornar a nova string numa nova
variavel.
*/