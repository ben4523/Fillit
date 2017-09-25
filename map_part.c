/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:41:58 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:41:08 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

/*
** Cette fonction va creer une liste t_map avec la taille
** precedement calculer et va la remplir que de .
** elle renvoie la liste de la map.
*/

t_map		*map_list_creat(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

/*
** Cette fonction va liberer un t_map liste
** proprement bloc par bloc et ne retourne rien
*/

void		free_map_list(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

/*
** Cette fonction va afficher la map sur la sortie standar
** elle ne retourne rien
*/

void		print_map_list(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** Cette fonction va verifier si la piece dans la map ne touche pas
** une autre ou ne sort pas de la map si elle est bonne elle la
** rajoute dans la liste.
** elle renvoie 1 si ses ok ou 0 si fail
*/

int			put_in_map(t_etris *tetris, t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
			if (tetris->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	in_good_place(tetris, map, point_creat_list(x, y), tetris->value);
	return (1);
}

/*
** Cette fonction va mettre dans la liste la pice en remplacent
** les point par la lettre alphabetique attribuer pour la pice
** elle ne renvoie rien
*/

void		in_good_place(t_etris *tetri, t_map *map, t_point *point, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->pos[j][i] == '#')
				map->array[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}
