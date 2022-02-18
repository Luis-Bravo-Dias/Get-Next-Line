/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:52:14 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/18 15:39:53 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while ((*str != '\0') && (*str != (unsigned char)c))
		str++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
	