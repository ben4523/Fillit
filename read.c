/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:04:11 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:41:09 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

/*
** Cette fonction va calculer la hauteur et la largeur de la
** piece. Elle fonctionne assez facilement caron s'est que on
** a 20 caracteres par piece donc si on croise un # avec
** plusieurs condition on va pouvoir trouver la taille de la
** piece final que nous stockon dans une 2 liste en paramettre
** grace a cette fonction on ses ou est placer le premier caract
** de la piece dans la map de la piece et pareil pour le dernier
** donc on a les 2 cordonner et la hauteur largeur.
*/

void				calc_with_heigth(char *str, t_point *min, t_point *max)
{
	int				i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

/*
** Cette fonction va prendre notre piece VALIDE et va la mettre dans
** une structure de liste, mais avant tout ca elle va calculer la
** hauteur et largeur de la piece qui est tres important pour la
** suite de programme. et aussi la postion du premier et dernier
** caractere. Un fois ca ok on va placer la piece dans un tableau
** qui nous a la mettre dans une liste. tout ca fait on free tout
** ce que nous avons plus besoin. On retourne la liste du tetris
*/

t_etris				*put_in_list(char *str, char letterto)
{
	int				i;
	char			**tab;
	t_point			*min;
	t_point			*max;
	t_etris			*tetris;

	min = point_creat_list(3, 3);
	max = point_creat_list(0, 0);
	calc_with_heigth(str, min, max);
	tab = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		tab[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(tab[i], str + (min->x) + (i + min->y) * 5,
			max->x - min->x + 1);
		i++;
	}
	tetris = add_tetris_list(tab, max->x - min->x + 1,
				max->y - min->y + 1, letterto);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetris);
}

/*
** Cette fonction verifie que entre chaque # il y a une liaison,
** Elle fonctionne assez simplement elle verifier le caractere
** en haut de la piece, en bas, a droit, a gauche.
** en fonction de la piece il y a 6 ou 8 connection car un
** caractere peux avoir plusieurs connections.
*/

int					check_piece_contact(char *str)
{
	int				def;
	int				i;

	def = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				def++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				def++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				def++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				def++;
		}
		i++;
	}
	return (def == 6 || def == 8);
}

/*
** Cette fonction va verifier que les caracteres de la peice qui sont dans
** le fichier sont soit de . ou #, elle va appeller aussi la fonction qui
** va verifier si il a toujours des liaisons entre chaque caractrere de la piece
** elle verifier aussi le nombre de ligne avec le nombre de column et aussi
** le \n a la fin de chaque ligne et aussi la ligne de separation entre piece
*/

int					check_piece(char *str, int counteur)
{
	int				i;
	int				def;

	def = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++def > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (counteur == 21 && str[20] != '\n')
		return (4);
	if (!check_piece_contact(str))
		return (5);
	return (0);
}

/*
** Cette fonction va lire le fichier et verifer qui les bon,
** gerer les erreurs et mettre le fichier dans plusieurs Liste chaine
** on rajoute tout les listes de chaque piece dans un tlist pour pouvoir
** tout les relier entre elle. et on le relie tout entre elle.
** on renvoie la liste Final.
*/

t_list				*read_files(int fd, int imp, int counteur)
{
	char			*buf;
	t_list			*list;
	t_etris			*tetris;
	char			letterto;

	buf = ft_strnew(21);
	list = NULL;
	letterto = 'A';
	while ((counteur = read(fd, buf, 21)) >= 20)
	{
		imp = (counteur == 20 ? 1 : imp);
		if (check_piece(buf, counteur) != 0
			|| (tetris = put_in_list(buf, letterto++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_tetris_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buf);
	if (counteur != 0 || imp == 0)
		return (free_tetris_list(list));
	list_r(&list);
	return (list);
}
