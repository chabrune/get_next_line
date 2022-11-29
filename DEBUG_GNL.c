/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG_GNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 06:54:50 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/29 07:16:06 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *stash);
char	*ft_line(char *stash);
char	*ft_save(char *save);

#endif

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1) // stash sera vide au premier appel
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

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

char	*ft_save(char *stash)
{
	int i;
	int j;
	char *end;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++; // i = 23
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	end = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1)); // "coucou je suis ton pDrM\nAt ta " strlen = 31 // i = 23
	if (!end)
		return (NULL);
	i++; // avancer apres le /n
	j = 0;
	while (stash[i])
		end[j++] = stash[i++]; // copie la suite de stash dans s
	end[j] = '\0';
	free(stash); // free stash et return end pour lire la prochaine line
	return (end);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}