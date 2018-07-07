/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:27:22 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/02 16:27:25 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*tetro_next_coordinate(char *s, int start, int skip, int tetro_num)
{
	int	x;
	int	y;
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 3);
	i = start;
	x = 0;
	y = 1;
	while (s[i] && skip >= 0)
	{
		if (s[i] == '\n')
			y++;
		if (s[i] == '#')
			skip--;
		i++;
	}
	(((i - ((tetro_num - 1) * 21)) % 10) > 5 && \
	((i - ((tetro_num - 1) * 21)) % 10) < 10) ? (x = (i - ((tetro_num - 1) *\
	21)) % 10 - 5) : (x = (i - ((tetro_num - 1) * 21)) % 10);
	arr[0] = x;
	arr[1] = y;
	arr[2] = i;
	return (arr);
}

int		**tetro_get_coordinates(char *s, int start, int end, int tetro_num)
{
	int	i;
	int	p;
	int	**arr;

	i = start;
	p = 0;
	arr = (int **)malloc(sizeof(int) * 9);
	while (p < 4 && start < end)
	{
		arr[p] = (int *)malloc(sizeof(int) * 3);
		arr[p][0] = tetro_next_coordinate(s, start, p, tetro_num)[0];
		arr[p][1] = tetro_next_coordinate(s, start, p, tetro_num)[1];
		arr[p][2] = tetro_next_coordinate(s, start, p, tetro_num)[2];
		p++;
	}
	return (arr);
}

int		**tetro_clean_coordinates(int **arr)
{
	if (arr[0][0] != 0 && arr[1][0] != 0 && arr[2][0] != 0 && arr[3][0] != 0)
		while (arr[0][0] != 0 && arr[1][0] != 0 && arr[2][0] != 0 &&\
			arr[3][0] != 0)
		{
			arr[0][0] -= 1;
			arr[1][0] -= 1;
			arr[2][0] -= 1;
			arr[3][0] -= 1;
		}
	if (arr[0][1] != 0 && arr[1][1] != 0 && arr[2][1] != 0 && arr[3][1] != 0)
		while (arr[0][1] != 0 && arr[1][1] != 0 && arr[2][1] != 0 &&\
			arr[3][1] != 0)
		{
			arr[0][1] -= 1;
			arr[1][1] -= 1;
			arr[2][1] -= 1;
			arr[3][1] -= 1;
		}
	return (arr);
}
