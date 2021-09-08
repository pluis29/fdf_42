/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:48:13 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:14:55 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	i;
	size_t	wrd;

	wrd = 0;
	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if (i == 0)
			wrd++;
		else if (s[i - 1] == c && s[i] != c)
			wrd++;
		i++;
	}
	return (wrd);
}

static size_t	ft_lenwrd(char const *s, char c)
{
	size_t		size;

	size = 0;
	while (s[size] != '\0' && s[size] != c)
		size++;
	return (size);
}

static char	**ft_free(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	wrd;
	size_t	i;
	size_t	size;

	i = 0;
	wrd = ft_countword(s, c);
	tab = (char **)malloc(sizeof(char *) * (wrd + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < wrd)
	{
		while (*s != '\0' && *s == c)
			s++;
		size = ft_lenwrd(s, c);
		tab[i] = ft_substr(s, 0, size);
		if (!tab[i])
			return (ft_free(tab, i));
		s += (size + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/*
	Cria uma tabela a partir das palavras que esta no parametro de 's'
é como se fosse a strtrim q remove o 'set' das pontas mas essa ela remove
de todos os lugares. E entao inseri na tabela em cada posição da tabela vai
ter uma palavra a partir da string passada Obs: sem os 'set' e a alocação 
acontece no substr.

	ft_countwrd conta quantas palavras sao para alocar espaço na tabela.
	ft_lenwrd conta quantos caracteres tem cada palavra e serve de parametro
para alocação.
	ft_free limpa primeiro todas as posições da tabela e por fim a tabela, mas
so acontece se a alocação do tamanho da palavra deu errado no substr.
*/