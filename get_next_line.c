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

void	read_into_temp(int fd, char *temp, int read_ret)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
		read_ret = 1;
	while (!ft_strchr(temp, '\n') && read_ret != 0)
	{
		read_ret = (int)read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free (buff);
			return ;
		}
		buff[BUFFER_SIZE + 1] = '\0';
		temp = ft_strjoin(temp, buff);
		free (buff);//pq vai ser overwritten pela função read
	}
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*temp;
	char		*line;
	int			read_ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read_ret = 1;
	line = NULL;
	read_into_temp(fd, &temp, &read_ret);
	if (!temp) //se o ficheiro estiver vazio
		return (NULL);
	// line = ft_strdup(temp);
	return (line);
}
