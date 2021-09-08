/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:04:24 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 23:14:36 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	x;

	if (nb == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb <= 9)
	{
		x = nb + '0';
		ft_putchar_fd(x, fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

/*
	Escreve o numero informado de acordo com 'fd'.

	Primeiro tratamento é para o overflow. Se o 'nb' for negativo escreve '-'
e converte o sinal. Por recursao ele vai separar os numero e dps fazer o modulo
assim q fizer o modulo ja entra no if se for verdade e escreve.
*/