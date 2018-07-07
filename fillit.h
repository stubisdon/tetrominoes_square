/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 18:16:49 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/06 14:26:18 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_piece
{
	char			symbol;
	char			*content;
	int				*boundry;
	struct s_piece	*next;
}					t_piece;

void				ft_print_board(char **board);
void				start_solve(t_piece *pieces);
int					solve(t_piece *l_pieces, char ***board, int size, \
					t_point p);
char				**make_board(int size);
int					get_min_board_size(t_piece *pieces);
int					*get_boundry_piece(char *piece);
int					check_valid_space(char *piece, char ***board, int x, \
					int y);
int					piece_placeable(char *piece, char ***board, int size, \
					t_point p);
int					put_piece(char *piece, char ***board, t_point p);
void				remove_piece(char ***board, char s);
int					valid_tetro_chars(char *s, int start, int end);
int					valid_tetro_map(char *s);
int					valid_tetro_connections(char *s, int start, int end, \
					int pos);
int					valid_tetro_connections_checker(char *s, int start, \
					int end);
char				tetro_symbol(int tetro_num);
int					*tetro_next_coordinate(char *s, int start, int skip, \
					int tetro_num);
int					**tetro_get_coordinates(char *s, int start, int end, \
					int tetro_num);
int					**tetro_clean_coordinates(int **arr);
char				*tetro_new_string(int **arr);
t_piece				*struct_new_piece(char *s, int tetro_num);
t_piece				*struct_make_list(t_piece *first_piece, char *s, \
					int tetro_num);
void				print_t_piece(t_piece *pieces);

#endif
