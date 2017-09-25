/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:17:37 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:41:09 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Cette fonction va calculer le nbr de piece mais avec la racine
** carrer ce qui va nous aider a trouver la taille de la map
** elle retourne la taille.
*/

int			resolution_part1(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

/*
** Cette fonction est une fonction de la libft qui permet
** de conte le nombre de block dan sune liste
*/

size_t		ft_count_list(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
** Cette fonction est une fonction backtrack qui va utiliser
** la recursiviter pour verifier l'endroit le plus optimiser
** pour cahque piece de la liste. elle appelle plusieurs fonctions
** qui verifie l'emplecement est bon.
** elle retourne 1 si ses bon ou 0 pour un fail
*/

int			resolve_map(t_map *map, t_list *list)
{
	int		x;
	int		y;
	t_etris	*tetris;

	if (list == NULL)
		return (1);
	y = 0;
	tetris = (t_etris *)(list->content);
	while (y < map->size - tetris->height + 1)
	{
		x = 0;
		while (x < map->size - tetris->width + 1)
		{
			if (put_in_map(tetris, map, x, y))
			{
				if (resolve_map(map, list->next))
					return (1);
				else
					in_good_place(tetris, map, point_creat_list(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Cette fonction resoudre le fillit
** elle fait appelle a plusieurs fonctions
** a la elle retourne la map avec les bon emplacement
** de chaque piece remplacer avec la lettre alphabetique
** a laquel elle correspond.
*/

t_map		*resolution(t_list *list)
{
	t_map	*map;
	int		size;

	size = resolution_part1(ft_count_list(list) * 4);
	map = map_list_creat(size);
	while (!resolve_map(map, list))
	{
		size++;
		free_map_list(map);
		map = map_list_creat(size);
	}
	return (map);
}
