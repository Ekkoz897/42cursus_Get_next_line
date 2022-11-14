/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:27:35 by apereira          #+#    #+#             */
/*   Updated: 2022/11/14 13:39:19 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*g;
	int		i;

	i = 0;
	g = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!g)
		return (NULL);
	while (s[i])
	{
		g[i] = s[i];
		i++;
	}
	g[i] = '\0';
	return (g);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destino;

	i = 0;
	source = (unsigned char *)src;
	destino = (unsigned char *)dest;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		destino[i] = source[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	str[ft_strlen(str)] = '\0';
	return (str);
}
