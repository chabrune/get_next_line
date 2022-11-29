/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 06:54:16 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/29 06:57:59 by chabrune         ###   ########.fr       */
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
	while (readed != 0 && (!ft_strchr(stash, '\n')))
	//strchr if !s null -- stash sera null 1er appel
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
} // je suis ton pere et je laime bien

char	*ft_line(char *stash) // je suis ton pere et je laime bi\nen
{
	int i;
	char *buff;
	
	i = 0;
	if (!stash[i]) // IMPORTANT SINON NE LIT PAS TOUTES LES LINE
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	buff = (char *)malloc((i + 2) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		buff[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		buff[i] = stash[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_save(char *save)
{
	int i;
	int c;
	char *s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}