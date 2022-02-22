/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:50:50 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/22 16:34:49 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*returner;
	size_t		valid;

//casos de erro
	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (0);
/* |||||||||||||||||||-Primeira Condição-||||||||||||||||||||

	size_t read (int fd, void* buf, size_t cnt);
	fd (primeiro slot) - File Descriptor
	buf (segundo slot) - buffer de onde os dados serão lidos
	cnt (terceiro slot) - tamanho do buffer
	
	Usa-se o read para para ver se existe ficheiro (fd) ou se é válido.
	File Descriptor (fd) é um int que identifica exclusivamente um arquivo aberto.
	O nulo (NULL) no segundo slot significa que tudo o que foi lido
	não será copiado para nada, ou seja, um buffer nulo. O zero (0) no terceiro slot
	indica que o buffer tem tamanho zero (0), ou seja, nada será lido.
	
	O retorno normal deveria ser 0, ou seja, que nada foi lido.
	Se o retorno for -1 então deu erro, o que significa que a função
	não conseguiu ler nada por ser inválida.

|||||||||||||||||||-Segunda Condição-||||||||||||||||||||

	O limite do só pode ter valores entre 0 e 1024, qualquer valor
	menor ou maior é invalido.

|||||||||||||||||||-Terceira Condição-||||||||||||||||||||
	O BUFFER_SIZE, que será dado pela flag do compilador, näo pode
	ser menor ou igual a zero, pois assim nada será lido.
*/
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
