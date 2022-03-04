/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:56:09 by lleiria-          #+#    #+#             */
/*   Updated: 2022/03/04 16:56:44 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	while ((*str != '\0') && (*str != (unsigned char)c))
		str++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(const char	*str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	size_t	count;

	if (dest == NULL && src == NULL)
		return (NULL);
	count = 0;
	while (count < n)
	{
		((char *)dest)[count] = ((const char *)src)[count];
		count++;
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	n;
	size_t	slen;

	slen = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (slen + 1));
	n = 0;
	if (p == NULL)
		return (NULL);
	while (s1[n] != '\0')
	{
		p[n] = s1[n];
		n++;
	}
	p[n] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	size_t	n1;
	size_t	n2;
	size_t	slen;

	if (!s1 || !s2)
		return (NULL);
	slen = ft_strlen(s1) + ft_strlen(s2);
	snew = (char *)malloc(sizeof(char) * (slen + 1));
	n1 = 0;
	n2 = 0;
	if (snew == NULL)
		return (NULL);
	while (s1[n1] != '\0')
	{
		snew[n1] = s1[n1];
		n1++;
	}
	while (s2[n2] != '\0')
	{
		snew[n1 + n2] = s2[n2];
		n2++;
	}
	snew[n1 + n2] = '\0';
	return (snew);
}
