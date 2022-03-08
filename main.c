/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:19:30 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/08 10:50:27 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h> //BOOLEAN
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		i;
	int		ctrl;
	bool	len;

	line = NULL;
	fd = open("line_1", O_RDONLY);
	i = 0;
	ctrl = 11;
	len = false;
	while ((line != NULL && ctrl < 0) || (i++ < ctrl && ctrl > 0))
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("line = %s", line);
		if (len)
			printf("len = %zu\n\n", ft_strlen(line));
		free(line);
	}
	close(fd);
	return (0);
}
