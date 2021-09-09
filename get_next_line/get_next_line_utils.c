/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:05:03 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/06/08 19:05:03 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	i = 0;
	if (len_dst < size)
	{
		while ((i + len_dst) < (size - 1) && src[i])
		{
			dst[i + len_dst] = src[i];
			i++;
		}
		dst[i + len_dst] = '\0';
	}
	return (len_dst + ft_strlen(src));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	while (src[len_src] != '\0')
	{
		len_src++;
	}
	if (size == 0)
	{
		return (len_src);
	}
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
