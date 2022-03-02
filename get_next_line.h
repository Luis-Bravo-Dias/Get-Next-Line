/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:46:54 by lleiria-          #+#    #+#             */
/*   Updated: 2022/03/02 17:16:28 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char	*str);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);

#endif