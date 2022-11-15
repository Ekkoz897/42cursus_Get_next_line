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

void	read_into_temp(int fd, char *temp, int read_ret)
{
	char	*buff;

	while (!ft_strchr(temp, '\n') && read_ret != 0)
	{
		buff = malloc(BUFFER_SIZE + 1); //dentro da loop para ir dando free
		if (!buff)
			return ;
		read_ret = 1;
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

// nl is the '\n' position in the array
// using a buffer "tmp_tmp" so that i can free the old temp malloc
void	clear_temp(char *temp, int nl)
{
	char	*tmp_tmp;

	tmp_tmp = temp;
	free (temp);
	temp = ft_substr(tmp_tmp, nl, ft_strlen(tmp_tmp + nl));
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	int			read_ret;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = NULL;
	read_ret = 1;
	line = NULL;
	read_into_temp(fd, temp, read_ret);
	if (!temp) //se o ficheiro estiver vazio
		return (NULL);
	len = cpy_line_only(temp);
	line = ft_substr(temp, 0, len);
	if (!line)
		return (NULL); // para o caso do malloc da substr correr mal
	clear_temp(temp, len);
	if (line[0] == '\0')
	{
		free(temp);
		free (line);
		return (NULL);
	}
	return (line);
}
