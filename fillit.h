/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:27:04 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:36:51 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <stdlib.h>

typedef struct				s_map
{
	int						size;
	char					**array;
}							t_map;
typedef struct				s_point
{
	int						x;
	int						y;
}							t_point;
typedef struct				s_etris
{
	char					**pos;
	int						width;
	int						height;
	char					value;
}							t_etris;

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

t_list						*read_files(int fd, int imp, int counteur);
int							check_piece(char *str, int counteur);
int							check_piece_contact(char *str);
void						calc_with_heigth(char *str, t_point *min,
								t_point *max);
t_point						*point_creat_list(int x, int y);
t_etris						*put_in_list(char *str, char letterto);
t_etris						*add_tetris_list(char **pos, int width,
								int height, char value);
t_list						*free_tetris_list(t_list *list);
void						free_tetris_tab(t_etris *tetris);
void						list_r(t_list **alst);
t_map						*resolution(t_list *list);
int							resolution_part1(int n);
t_map						*map_list_creat(int size);
int							put_in_map(t_etris *tetris, t_map
								*map, int x, int y);
void						in_good_place(t_etris *tetri, t_map *map,
								t_point *point, char c);
size_t						ft_count_list(t_list *lst);
void						free_map_list(t_map *map);
void						print_map_list(t_map *map);
void						ft_putstr(char const *s);
void						ft_lstadd(t_list **alst, t_list *new);
void						ft_lstdel(t_list **alst,
								void (*del)(void *, size_t));
t_list						*ft_lstnew(void const *content,
								size_t content_size);
void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
void						ft_putchar(char c);
char						*ft_strnew(size_t size);
void						ft_putstr(char const *s);
void						*ft_memcpy(void *dest, const void *src, size_t n);
char						*ft_strncpy(char *dest, const char *src, size_t n);
#endif
