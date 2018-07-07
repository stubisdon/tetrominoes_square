/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:25:08 by juwong            #+#    #+#             */
/*   Updated: 2018/07/06 13:55:43 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_board(char **board)
{
	if (!board)
		return ;
	while (*board)
	{
		ft_putstr(*board++);
		ft_putchar('\n');
	}
}

char	**make_board(int size)
{
	char	**board;
	char	**ptr;
	int		i;

	i = 0;
	board = (char**)malloc(sizeof(*board) * (size + 1));
	ptr = board;
	while (i < size)
	{
		*board = ft_strnew(size);
		*board = ft_memset(*board, '.', size);
		board++;
		i++;
	}
	*board = 0;
	return (ptr);
}

int		get_min_board_size(t_piece *pieces)
{
	int		i;
	int		sqroot;

	i = 0;
	sqroot = 2;
	while (pieces)
	{
		pieces = pieces->next;
		i++;
	}
	i = i * 4;
	while (sqroot * sqroot < i)
		sqroot++;
	return (sqroot);
}
