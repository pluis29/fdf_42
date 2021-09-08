/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:47:36 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/01 22:24:26 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	head = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}

/*
	Cria uma nova lista do tamanho da lst porem com content especificos.

	lstnew recebe uma função como parametro ou seja essa função do parametro
esta criando uma informação para ser passada de content para os lstnew q vai
criar um elemento com aquele content. Se for NULL da clear Obs: usamos '&'
porque é ponteiro duplo.
	lstadd_back adciona o novo elemento criado no fim do head(a nova lista).
*/