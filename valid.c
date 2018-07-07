/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:38:48 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/30 12:38:56 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_tetro_chars(char *s, int start, int end)
{
	int	i;
	int	t;
	int endline;

	i = start;
	t = 0;
	endline = i + 4;
	while (endline < end)
	{
		if (s[endline] != '\n')
			return (0);
		endline = endline + 5;
	}
	while (i < end)
	{
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		if (s[i] == '#')
			t++;
		i++;
	}
	if (t == 4)
		return (1);
	else
		return (0);
}

int	valid_tetro_connections(char *s, int start, int end, int pos)
{
	int	i;
	int	c;

	i = pos;
	c = 0;
	if (s[i] == '#' && i != start && s[i - 1] == '#')
		c++;
	if (s[i] == '#' && i != end && s[i + 1] == '#')
		c++;
	if (s[i] == '#' && i > (start + 4) && s[i - 5] == '#')
		c++;
	if (s[i] == '#' && i < (end - 5) && s[i + 5] == '#')
		c++;
	return (c);
}

int	valid_tetro_connections_checker(char *s, int start, int end)
{
	int	i;
	int	c;

	i = start;
	c = 0;
	while (i < end)
	{
		c += valid_tetro_connections(s, start, end, i);
		i++;
	}
	return (c);
}

/*
** valid_tetro_map doesn't account for ending with an empty line
*/

int	valid_tetro_map(char *s)
{
	int	i;
	int	tetro;

	i = 0;
	tetro = 0;
	while (s[i])
	{
		if (valid_tetro_chars(s, i, i + 19) == 1 && \
		(valid_tetro_connections_checker(s, i, i + 19) == 6 || \
		valid_tetro_connections_checker(s, i, i + 19) == 8))
		{
			tetro++;
			i = i + 20;
			if (s[i] == '\0')
				return (tetro);
			if ((s[i] == '\n' && s[i + 1] == '\0') \
			|| s[i] == '.' || s[i] == '#')
				return (0);
			if (s[i] == '\n' && s[i + 1] != '\n')
				i++;
		}
		else
			return (0);
	}
	return (tetro);
}
