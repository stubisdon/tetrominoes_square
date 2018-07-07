/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:51:07 by juwong            #+#    #+#             */
/*   Updated: 2018/07/06 15:20:27 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*get_boundry_piece(char *piece)
{
	int		i;
	int		j;
	int		max_i;
	int		*boundry;

	i = 0;
	j = 1;
	max_i = 0;
	boundry = (int *)malloc(sizeof(int) * 2);
	while (*piece)
	{
		if (*piece == '\n')
		{
			j++;
			max_i = max_i < i ? i : max_i;
			i = 0;
		}
		else
			i++;
		piece++;
	}
	boundry[0] = max_i;
	boundry[1] = j;
	return (boundry);
}

void	remove_piece(char ***board, char s)
{
	char	**ptr_board;
	int		i;
	int		k;

	ptr_board = *board;
	k = 0;
	while (ptr_board[k])
	{
		i = 0;
		while (ptr_board[k][i])
		{
			if (ptr_board[k][i] == s)
				ptr_board[k][i] = '.';
			i++;
		}
		k++;
	}
}

int		check_valid_space(char *piece, char ***board, int x, int y)
{
	char	*ptr;
	int		i;

	ptr = piece;
	i = 0;
	while (*ptr)
	{
		if (ft_isalpha(*ptr))
		{
			if ((*board)[y][i + x] == '.')
				i++;
			else
				return (0);
		}
		else if (*ptr == '.')
			i++;
		else if (*ptr == '\n')
		{
			y++;
			i = 0;
		}
		ptr++;
	}
	return (1);
}

int		put_piece(char *piece, char ***board, t_point p)
{
	char	**board2;
	int		k;

	board2 = *board;
	if (!piece)
		return (0);
	k = p.x;
	while (*(char*)piece)
	{
		if (ft_isalpha(*(char*)piece))
		{
			board2[p.y][k] = *(char*)piece;
			k++;
		}
		else if (*((char*)piece) == '.')
			k++;
		else if (*((char*)piece) == '\n')
		{
			p.y++;
			k = p.x;
		}
		piece++;
	}
	return (1);
}
