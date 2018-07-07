/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:34:44 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/06 21:35:42 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*tetro_new_string(int **arr)
{
	INT;
	ZERO;
	s = (char *)malloc(sizeof(char) * 25);
	while (p < 4)
	{
		if (y == arr[p][1])
		{
			p += (x++ == arr[p][0]);
			s[i++] = (x == arr[p][0] ? '#' : '.');
		}
		else
		{
			while (x <= (arr[3][0] || x <= arr[2][0] || x <= arr[1][0]))
			{
				s[i++] = '.';
				x++;
			}
			s[i++] = '\n';
			x = 0;
			y++;
		}
	}
	s[i] = '\0';
	return (s);

	int	main()
	{
		int **arr = (int **)malloc(4 * sizeof(int *));
		int i = 0;
		while (i < 4)
		{
			arr[i] = (int *)malloc(2 * sizeof(int));
			i++;
		}
		int a = 4;
		int b = 2;

		arr[0][0] = 1;
		arr[0][1] = 0;
		arr[1][0] = 0;
		arr[1][1] = 1;
		arr[2][0] = 1;
		arr[2][1] = 1;
		arr[3][0] = 2;
		arr[3][1] = 2;

		printf("%s\n", tetro_new_string(arr));
		return (0);
	}

