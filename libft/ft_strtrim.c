/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:15:38 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:16:53 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	start = ft_strlen(s1);
	while (start && ft_strchr(set, s1[start]))
		start--;
	return (ft_substr(s1, 0, start + 1));
}

/*
	Cria uma string no qual eliminamos todos os parametros de 'set' no começo e
no fim da string(mas nao no meio). Retorna essa strin sem a influencia do 'set.

	Primeiro while faz com que 'o endereço de memoria se movimente e aponte
para a posição atual' enquanto s1 diferente de null e strchr for verdadeiro.
	Assim pegamos o tamanho de 's1' sem os caracteres indesejados de 'set' no
começo, mas precisamos saber se existe no fim entao fazemos a mesma coisa de
tras para frente '<-'.
	O retorno é feito com substr pois ja sabemos q s1 aponta para o endereço
onde ja nao tem mais o 'set' no começo entao falamos 0 para começar de la,
e o fim é o start que quer dizer que ele tambem ja eliminou todas as influencias
de set. Obs: a alocação de memoria acontece em substr.
*/