/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:48:13 by hrhilane          #+#    #+#             */
/*   Updated: 2024/12/24 19:48:16 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!saved || !(strchr(saved, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(saved);
			saved = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	if (!saved)
		return (NULL);
	if (strchr(saved, '\n'))
	{
		line = ft_substr(saved, 0, strchr(saved, '\n') - saved + 1);
		saved = strdup(strchr(saved, '\n') + 1);
        if (saved && saved[0] == '\0')
        {
            free(saved);
            saved = NULL;
        }
		return (line);
	}
	line = strdup(saved);
	free(saved);
	saved = NULL;
	return (line);
}

int	main(void)
{
    int		fd;
    char	*line;

    fd = open("normal.txt", O_RDONLY | O_CREAT, 0644);
    if (fd < 0)
    {
        printf("Error opening file");
        return (1);
    }
    line = get_next_line(fd);
    if (line)
    {
        printf("%s", line);
        free(line);
    }
    else
        printf("No line read or an error occurred.\n");
    printf("2nd call\n");
    line = get_next_line(fd);
    if (line)
    {
        printf("%s", line);
        free(line);
    }
    else
        printf("No line read or an error occurred.\n");
    close(fd);
    return (0);
}
