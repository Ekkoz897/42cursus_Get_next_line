/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:41:39 by apereira          #+#    #+#             */
/*   Updated: 2022/11/17 15:22:48 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	int			len;
	char		*tmp_tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	read_into_temp(fd, temp);
	if (!temp)
		return (NULL);
	len = cpy_line_only(temp);
	line = ft_substr(temp, 0, len);
	if (!line)
		return (NULL);
	tmp_tmp = temp;
	temp = ft_substr(tmp_tmp, len, ft_strlen(tmp_tmp + len));
	free (temp);
	return (line);
}

char	*ft_free(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free(res);
	return (temp);
}

void	read_into_temp(int fd, char *temp)
{
	int		read_ret;
	char	*buff;

	if (!temp)
	{
		temp = malloc(1 * sizeof(char));
		temp[0] = '\0';
	}
	read_ret = 1;
	while (read_ret != 0)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_ret = (int)read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free (buff);
			return ;
		}
		buff[read_ret] = '\0';
		temp = ft_free(temp, buff);
		if (ft_strchr(temp, '\n'))
			break ;
	}
}

int	cpy_line_only(char *temp)
{
	size_t	i;
	size_t	len;

	if (!temp)
		return (0);
	len = 0;
	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			len ++;
			break ;
		}
		len++;
		i++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*g;
	int		i;

	i = 0;
	g = ft_calloc(sizeof(char) * (ft_strlen(s) + 1), sizeof(char));
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
