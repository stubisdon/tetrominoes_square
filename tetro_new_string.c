/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_new_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 17:07:00 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/06 17:07:02 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include <stdio.h>

int		*max(int **arr)
{
	int	*max;
	int bx;
	int by;

	max = (int *)malloc(sizeof(int) * 3);
	bx = 0;
	by = 0;
	while (bx < arr[0][0] || bx < arr[1][0] || bx < arr[2][0] || bx < arr[3][0])
		bx++;
	while (by < arr[0][1] || by < arr[1][1] || by < arr[2][1] || by < arr[3][1])
		by++;
	max[0] = bx;
	max[1] = by;
	return (max);
}

char	counter(int **arr, int i, int p)
{
	int	y;
	int	x;

	if (max(arr)[1] != 0)
	{
		y = i / (max(arr)[0] + 2);
		x = i % (max(arr)[0] + 2);
	}
	else
	{
		y = 0;
		x = i;
	}
	if (y == arr[p][1])
	{
		if (x == arr[p][0])
			return ('#');
		else
			return ('.');
	}
	else
	{
		if (x <= max(arr)[0])
			return ('.');
		else
			return ('\n');
	}
}

char *tetro_new_string(int **arr)
{
	char	*s;
	int		i;
	int		p;

	i = 0;
	p = 0;
	s = (char *)malloc(sizeof(char) * 25);
	while (p < 4)
	{
		s[i] = counter(arr, i, p);
		if (s[i] == '#')
			p++;
		i++;
	}
	s[i] = '\0';
	return (s);
}
/*
int	main()
{
	int **arr = (int **)malloc(4 * sizeof(int *));
	int i = 0;
	while (i < 4)
	{
		arr[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}

	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 2;
	arr[1][1] = 0;
	arr[2][0] = 0;
	arr[2][1] = 1;
	arr[3][0] = 1;
	arr[3][1] = 1;

	printf("%s\n", tetro_new_string(arr));
	return (0);
}
*/
