/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:12:17 by mrolain           #+#    #+#             */
/*   Updated: 2024/07/24 05:29:11 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	*ft_free(char *str, char *strr)
{
	if (str)
		free(str);
	if (strr)
		free(strr);
	return (NULL);
}

char	*next_stash(char *stash)
{
	char	*stash2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (ft_free(stash, NULL));
	i++;
	stash2 = malloc(sizeof(char) * ft_strlen(stash));
	if (!stash2)
		return (NULL);
	while (stash[i])
	{
		stash2[j] = stash[i];
		i++;
		j++;
	}
	stash2[j] = '\0';
	free(stash);
	return (stash2);
}

char	*treat_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(stash, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(stash, buffer));
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (ft_free(stash, NULL));
	}
	free (buffer);
	if (bytes_read == 0 && stash[bytes_read] == '\0')
		return (ft_free(stash, NULL));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = treat_line(stash);
	stash = next_stash(stash);
	return (line);
}

// int main(void)
// {
// 	int	fd = open("test.txt", O_RDONLY);
// 	char *str;
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
