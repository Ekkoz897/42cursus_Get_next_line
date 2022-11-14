/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:41:39 by apereira          #+#    #+#             */
/*   Updated: 2022/11/14 15:24:44 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*get_next_line(int fd)
{
	void		*buff;
	static char	*temp;
	char		*line;

	buff = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(temp, '\n'))
	{
		read(fd, buff, BUFFER_SIZE);
		temp = ft_strjoin(temp, buff);
	}
	line = ft_strdup(temp);
	free(buff);
	return (temp);
}
