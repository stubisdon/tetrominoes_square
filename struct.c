/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 23:18:04 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/04 15:45:36 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	tetro_symbol(int tetro_num)
{
	char	sym;

	sym = tetro_num + 64;
	return (sym);
}

char	*tetro_mod(char *s, char symbol)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			s[i] = symbol;
		i++;
	}
	return (s);
}

t_piece	*struct_new_piece(char *s, int tetro_num)
{
	t_piece	*piece;
	int		start;
	int		end;

	start = (tetro_num - 1) * 21;
	end = start + 19;
	if ((piece = (t_piece *)malloc(sizeof(*piece))) == NULL)
		return (NULL);
	if (s == NULL || tetro_num == 0)
	{
		piece->symbol = 0;
		piece->content = NULL;
	}
	else
	{
		piece->symbol = tetro_symbol(tetro_num);
		piece->content = tetro_mod(tetro_new_string(tetro_clean_coordinates(\
			tetro_get_coordinates(s, start, end, tetro_num))),\
			tetro_symbol(tetro_num));
		piece->boundry = get_boundry_piece(piece->content);
	}
	piece->next = NULL;
	return (piece);
}

t_piece	*struct_make_list(t_piece *first_piece, char *s, int tetro_num)
{
	t_piece	*piece;
	int		i;
	int		t;

	i = (tetro_num - 1) * 21;
	t = 2;
	piece = first_piece;
	if (s == NULL || tetro_num == 0)
	{
		piece->symbol = 0;
		piece->content = NULL;
	}
	else
	{
		while (t <= tetro_num)
		{
			piece->next = struct_new_piece(s, t);
			i = i + 21;
			t++;
			piece = piece->next;
		}
	}
	return (first_piece);
}

void	print_t_piece(t_piece *pieces)
{
	while (pieces != NULL)
	{
		ft_putchar(pieces->symbol);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putstr(pieces->content);
		ft_putchar('\n');
		ft_putchar('\n');
		pieces = pieces->next;
	}
	return ;
}
