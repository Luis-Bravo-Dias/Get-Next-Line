/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:50:50 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/18 17:08:09 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*returner;
	size_t		valid;

	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (0);
	valid = 1;
	returner = NULL;
	buffer = ft_strchr(storage, '\n');
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
	}
}
