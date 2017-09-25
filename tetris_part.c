/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:38:18 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:41:10 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Cette fonction va creer une liste t_point avec les variable x y
** envoyer en paramettre dans la liste.
** elle retourne la liste
*/

t_point		*point_creat_list(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

/*
** Cette fonction va creer une liste chainer avec les varible du tetris
** et nous renvoie cette liste.
*/

t_etris		*add_tetris_list(char **pos, int width, int height, char value)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

/*
** Cette fonction va liberer la memoire de la liste proprement
** passer en paramettre et elle va nous retourner NULL
*/

t_list		*free_tetris_list(t_list *list)
{
	t_etris	*tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_etris *)list->content;
		next = list->next;
		free_tetris_tab(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

/*
** Cette fonction va liberer la memoire de la chaque element
** de la liste proprement
** passer en paramettre et elle va nous retourner rien
*/

void		free_tetris_tab(t_etris *tetris)
{
	int y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)(&(tetris->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetris->pos)));
	ft_memdel((void **)&tetris);
}

/*
** Cette fonction va refaire les connction de la liste
** elle ne renvoie rien
*/

void		list_r(t_list **alst)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = *alst;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*alst = prev;
}
