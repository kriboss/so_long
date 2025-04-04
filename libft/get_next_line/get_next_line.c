/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:49:33 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/30 00:44:28 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

static char	*free_join(char *buffer, char *text)
{
	char	*ris;

	ris = ft_strjoin(buffer, text);
	free(buffer);
	return (ris);
}

static char	*read_buffer(int fd, char *buffer)
{
	int		len;
	char	*text;

	len = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	text = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!text)
		return (NULL);
	while (len > 0)
	{
		len = read(fd, text, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			free(text);
			return (NULL);
		}
		text[len] = '\0';
		buffer = free_join(buffer, text);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(text);
	return (buffer);
}

static char	*trim_buffer(char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (!str)
		return (NULL);
	while (buffer[++i])
		str[j++] = buffer[i];
	str[j] = '\0';
	free(buffer);
	return (str);
}

static char	*read_the_line(char *buffer)
{
	int		i;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*buffer;

	res = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	res = read_the_line(buffer);
	buffer = trim_buffer(buffer);
	return (res);
}
