/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 06:54:16 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/29 19:51:25 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_save(stash);
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	char	*buff;
	int		readed;

	readed = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (readed > 0 && (!ft_strchr(stash, '\n')))
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed < 0)
		{
			free(stash);
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		stash = ft_strjoin(stash, buff);
		if (!stash)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
	}
	free(buff);
	return (stash);
}

char	*ft_line(char *stash)
{
	int		i;
	char	*buff;

	i = 0;
	if (!stash[i] || !stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (ft_strchr(stash, '\n'))
		buff = (char *)malloc((i + 2) * sizeof(char));
	else
		buff = (char *)malloc((i + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		buff[i] = stash[i];
	if (stash[i] == '\n')
	{
		buff[i] = stash[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_save(char *stash)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash)
	{
		free(stash);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		s[j++] = stash[i++];
	s[j] = '\0';
	free(stash);
	return (s);
}
