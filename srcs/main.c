/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:34:19 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 15:13:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int				main(int argc, char **argv)
{
	int		fd;
	char	**map;
	t_tetro	*list_input;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error when openning the file. Did you check the name ?\n");
		return (-1);
	}
	list_input = input(fd);
	if (!list_input || close(fd) == -1)
	{
		ft_putstr("File format not respected.\n");
		return (-1);
	}
	map = solver_init(list_input);
	tetrodel(&list_input);
	print_map(map);
	free_map(map);
}
