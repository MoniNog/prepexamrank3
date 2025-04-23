/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projet_GNL.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:20:04 by moni              #+#    #+#             */
/*   Updated: 2025/04/15 12:31:54 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/// @brief search new line
/// @param s str
/// @return NULL = no \n || s = pos of '\n'
char	*ft_strchr_newline(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	dest = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (!dest)
			return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

// In ft_strchr_newline, I've adapted strchr for clarity: it specifically 
// looks for '\n'.

// In ft_strjoin, s1 is freed at line 59. This is specific to its use in GNL
// where s1 holds data that has already been read and accumulated. After
// concatenation with s2, s1 is no longer needed, so freeing s1 helps prevent
// memory leaks.

char	*read_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
	bytes_read = 1;
	while (!ft_strchr_newline(line) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == -1)
			{
				free(buffer);
				return (NULL);
			}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*extract_line(char *line)
{
	char	*extracted_line;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	extracted_line = (char *)malloc(i + 2);
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		extracted_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		extracted_line[i] = line[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

char	*remove_line(char *line)
{
	char	*text_after_extraction;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	len = ft_strlen(line) - i;
	text_after_extraction = (char *)malloc(len + 1);
	if (!text_after_extraction)
		return (NULL);
	i++;
	while (line[i])
		text_after_extraction[j++] = line[i++];
	text_after_extraction[j] = '\0';
	free(line);
	return (text_after_extraction);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	
	static_buffer = read_line(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = extract_line(static_buffer);
	static_buffer = remove_line(static_buffer);
	return (line);
}

/*	read_line:
	Reads data from the file specified by fd into a buffer, concatenates it to
	'line' until a newline character ('\n') or the end of the file is found.
	Frees the temporary buffer and returns the accumulated string. */

/*	extract_line:
	Extracts the first line (up to the first '\n', inclusive) from the string
	'line'. Allocates and returns a new string containing this extracted line.
	*/

/*	remove_line:
	Removes the first line from the string 'line' and returns the rest. If 
	'line' starts with a '\n', this function creates a new string without this
	leading '\n' and the preceding part of 'line', freeing the old string. */

/*	get_next_line:
	The main function that uses a static buffer to accumulate data read from
	the file descriptor 'fd'. It reads data by calling read_line, extracts the
	first available line with extract_line, and updates the static buffer by
	removing this line with remove_line. Returns the extracted line or NULL if
	the end of the file is reached or in case of an error. */

	int main(int ac, char **av)
	{
		int fd = open("text.txt", O_RDONLY);
		if (fd == -1)
		{
			perror("fd\n");
			return 1;
		}
		char	*line = get_next_line(fd);
		printf("line 1 : %s\n", line);
		line = get_next_line(fd);
		printf("line 2 : %s\n", line);

	}