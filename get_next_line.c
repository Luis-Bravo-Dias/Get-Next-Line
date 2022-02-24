/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:50:50 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/24 18:36:37 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char *valid_buffer(char **storage, char **buffer, size_t buflen)
{
	char	*returner;
	char	*tmp;
	size_t	storlen;

	storlen = ft_strlen(*storage);
	returner = (char *)malloc(sizeof(char) * buflen + storlen + 1);
	if (!ret)
		return (0);
}

static	char *feed_storage(char **storage, char **buffer, size_t valid)
{
	char	*tmp;
	char	*returner;

	returner = NULL;
	if (valid <= 0)// se valid for menor ou igual a 0, então o ficheiro já foi lido ou é inválido
	{
		if (valid == 0 && *storage)//verificamos também se existe algo na storege, pois
//		o ficheiro pode ser válido, mas estar vazio.
		{
			returner = (*storage);//Redireciona-se o ponteiro returner para o conteudo da storage
			*storage = NULL;//enquanto a storage passa a apontar para nulo.
		}
		return (returner);
	}
	(*buffer)[valid] = '\0';
	tmp = ft_strchr(*buffer, '\n');//procurar uma nova linha no buffer
	if (tmp)
		returner = valid_buffer(storage, buffer, (tmp - *buffer) + 1);
/*
	Se existir tmp, ou seja, se existir uma nova linha, usamos a funçāo
	valid_buffer onde enviamos a storage, o buffer e o endereço de tmp
	menos (-) o endereço inicial do buffer (o que será o tamanho da string
	dentro do buffer) + 1 espaço para o nulo no final.
*/
}

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

	O limite do fd só pode ter valores entre 0 e 1024, qualquer valor
	menor ou maior é invalido.

|||||||||||||||||||-Terceira Condição-||||||||||||||||||||
	
	O BUFFER_SIZE, que será dado pela flag do compilador, näo pode
	ser menor ou igual a zero, pois assim nada será lido.
*/
	valid = 1;
	returner = NULL;
	buffer = ft_strchr(storage, '\n');
/*	com o ft_strchr verificamos se existe algo no armazenamento (storage) e se caso
	exista enviamos o seu conteudo até à primeira quebra de linha (\n) encontrada
	para o buffer
*/
//caso o buffer esteja vazio ou não haja quebra de linha, é necessário enchê-lo
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
//Alocamos a memória necessária para o buffer + 1 espaço para o nulo do final da string
		if (!buffer)//Se mesmo assim não existir nada no buffer, então deu erro
			return (0);
/*  /////////////////-Condições do While-//////////////
	Devido à função feed_storage, o returner só deixará de ser ser nulo se o
	buffer encontrar uma nova linha.

	Enquanto valid for maior que 0, significa que ainda há conteudo para ser
	lido no ficheiro.
	Se valid chegar a 0 também significa que o buffer está vazio e que tudo o
	que restava retornar já está na storage.
	Desse modo, o returner já não será nulo e o while loop para.
*/
		while (returner == NULL && valid > 0)
		{
			valid = read(fd, buffer, BUFFER_SIZE);
//Lemos (read) um BUFFER_SIZE número de caracteres e armazenamos no ponteiro buffer (nāo entendi)
			returner = feed_storage(&storage, &buffer, valid);
//Enchemos entāo a storage com tudo o que o buffer encontrar e colocar no returner a storage ou o buffer
		}
		free (buffer);
		return (returner);
	}
}
