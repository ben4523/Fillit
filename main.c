/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:26:48 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:41:07 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

/*
** On commence le traitemant du fichier et on le resoue on appelle
** les fonctions qui vont le traiter
** elle va traiter le fichier et afficher le resulatat sur la sortie
** standar
*/

int				main(int argc, char **argv)
{
	t_list		*list_end;
	t_map		*maping;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(1);
	}
	if ((list_end = read_files(open(argv[1], O_RDONLY), 0, 0)) == NULL)
	{
		ft_putstr("error\n");
		exit(1);
	}
	maping = resolution(list_end);
	print_map_list(maping);
	free_map_list(maping);
	free_tetris_list(list_end);
	return (0);
}
