/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:00:21 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/05 19:34:57 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

#define BUF_SIZE 560

int	opener(int fd, char *buf)
{
	int		ret;
	t_piece	*l_piece;
	t_piece	*f_piece;

	ret = read(fd, buf, BUF_SIZE);
	if (valid_tetro_map(buf) > 0 && valid_tetro_map(buf) <= 26)
	{
		f_piece = struct_new_piece(buf, 1);
		l_piece = struct_make_list(f_piece, buf, valid_tetro_map(buf));
		start_solve(l_piece);
		return (0);
	}
	else
	{
		ft_putstr("error\n");
		return (1);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			opener(fd, buf);
		}
		else
		{
			ft_putstr("cannot read the file");
			return (2);
		}
		close(fd);
	}
	else
	{
		ft_putstr("usage: ./fillit file_with_tetrominoes");
	}
	return (0);
}
