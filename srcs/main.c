/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:28:06 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/07 21:28:06 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/**
 * malloc da struct
 * check argumento
 * inicializacao
 * redirecionamento para parse
*/
int	main(int ac, char **av)
{
	t_fdf *info;

	if (ac != 2)
		handle_error("Usage invalid: ./fdf 'map'");
	info = malloc(sizeof(t_fdf));
	if (!info)
		handle_error("malloc error");
	//set_info(info);
	parse_map(info, av[1]);
}

/**
 * em progresso
*/
static void	set_info(t_fdf *info)
{

}