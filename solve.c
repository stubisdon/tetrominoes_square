/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:43:53 by juwong            #+#    #+#             */
/*   Updated: 2018/07/06 13:55:05 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(t_piece *l_pieces, char ***board, int size, t_point p)
{
	t_point		np;
	int			res;

	if (!l_pieces)
		return (1);
	np.x = 0;
	np.y = 0;
	while (p.x + l_pieces->boundry[0] <= size && p.y + l_pieces->boundry[1] \
		<= size)
	{
		if (check_valid_space(l_pieces->content, board, p.x, p.y))
		{
			put_piece(l_pieces->content, board, p);
			res = solve(l_pieces->next, board, size, np);
			if (res == 1)
				return (1);
			remove_piece(board, l_pieces->symbol);
		}
		if (++(p.x) + l_pieces->boundry[0] > size)
		{
			p.y++;
			p.x = 0;
		}
	}
	return (0);
}

void	start_solve(t_piece *l_pieces)
{
	char		**board;
	int			size;
	t_point		p;

	size = get_min_board_size(l_pieces);
	board = make_board(size);
	p.x = 0;
	p.y = 0;
	while (!(solve(l_pieces, &board, size, p)))
	{
		size++;
		free(board);
		board = make_board(size);
	}
	ft_print_board(board);
}
