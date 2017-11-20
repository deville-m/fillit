/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:58:17 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 17:36:42 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

static inline t_tetro	*free_and_null(t_tetro **res)
{
	tetrodel(res);
	return (NULL);
}

static int				valid_number(unsigned int n)
{
	return (n == 14980
			|| n == 10580
			|| n == 4780
			|| n == 5480
			|| n == 5780
			|| n == 14380
			|| n == 11140
			|| n == 6020
			|| n == 4840
			|| n == 4820
			|| n == 5460
			|| n == 10920
			|| n == 14700
			|| n == 5800
			|| n == 5420
			|| n == 10900
			|| n == 14420
			|| n == 5060
			|| n == 10600);
}

static unsigned int		check_piece(const char *buff)
{
	char			res[17];
	int				i;
	size_t			cpt;
	size_t			width;
	unsigned int	n;

	cpt = 0;
	i = 0;
	width = 0;
	while (i < 20)
	{
		if (buff[i] == '.' || buff[i] == '#')
		{
			res[cpt++] = buff[i];
			width++;
		}
		else if (width != 4)
			return (0);
		else if (buff[i] == '\n')
			width = 0;
		i++;
	}
	res[cpt] = '\0';
	n = num_piece(res);
	return ((valid_number(n)) ? n : 0);
}

t_tetro					*input(int fd)
{
	int				nbread;
	t_tetro			*res;
	t_tetro			*new;
	char			buffer[21];
	int				nbtetros;

	nbtetros = 0;
	while ((nbread = read(fd, buffer, 21)) == 21)
	{
		if (buffer[20] != '\n' || !check_piece(buffer)
			|| !(new = tetronew(ft_strsplit(buffer, '\n'))))
			return (free_and_null(&res));
		tetroadd(&res, new);
		nbtetros++;
	}
	if (nbread == 20 && check_piece(buffer) && nbtetros + 1 <= 26
			&& (new = tetronew(ft_strsplit(buffer, '\n'))))
		tetroadd(&res, new);
	else
		return (free_and_null(&res));
	return (res);
}
