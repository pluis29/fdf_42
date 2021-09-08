/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:33:19 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 22:22:48 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			sign;
	int			size;
	char		*conv;
	long int	nn;

	sign = n < 0;
	nn = n;
	if (sign > 0)
		nn = -nn;
	size = 1;
	while (n / 10 != 0 && size++)
		n /= 10;
	conv = malloc(sizeof(char) * (size + sign + 1));
	if (!conv)
		return (NULL);
	conv[size + sign] = '\0';
	while (size-- != 0)
	{
		conv[size + sign] = nn % 10 + '0';
		nn /= 10;
	}
	if (sign > 0)
		conv[0] = '-';
	return (conv);
}

/*
	Converte int para char.

	sign = n < 0 quer dizer, se a comparacao logica for verdadeira retorna 
1 para verdadeiro e 0 para falso.
	Se sign for 1 quer dizer que 'n' < 0 entao meu 'nn' vira '-nn'.
	Primeiro while vai contar quantos numeros sao, dividindo por 10 ate der 0
o size começa como 1 porque ele nao faz a ultima conta quando deveria dar 0.
	Aloca memoria para quantidade certa de numeros se tiver sinal o sign vale 1
se nao ele vale 0 e nao influencia no malloc +1 para por o \0.
	Tem q fazer de traz para frente pois usamos modulo e 'divisao interativa'
coloca null o modulo vai pegar o ultimo numero e ja adicionar a variavel dps 
o nn = nn / 10 elimina o numero ja alocado.
	Se o sign for 1 coloca o '-' no começo.
*/
