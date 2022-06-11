/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:41:47 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 20:55:11 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void	print_frame_number(t_env *e, t_index *col)
{
	char	c[2];

	c[1] = '\0';
	while (*col < e->b.col + 2 && *col < 15)
	{
		if (*col - 2 < 10)
		{
			c[0] = *col - 2 + '0';
			ft_pb(false, c);
			ft_pb(false, " ");
		}
		else
			ft_pb(false, ". ");
		*col += 1;
	}
	*col += 15;
	ft_pb(false, "  ");
}

static void	print_frame_line(t_env *e, const bool n)
{
	t_index	col;

	ft_pb(false, C_FRAME);
	col = -1;
	while (++col < 2)
		ft_pb(false, " ");
	if (n)
		print_frame_number(e, &col);
	while (++col < (e->b.col * COIN_SIZE + 5))
		ft_pb(false, " ");
	ft_pb(false, "\033[0m\033[K\n");
}

static void	print_coin(t_env *e, const t_coin coin)
{
	if (coin == USER)
	{
		ft_pb(false, e->c_user);
		ft_pb(false, COIN_USER);
	}
	else if (coin == AI)
	{
		ft_pb(false, e->c_ai);
		ft_pb(false, COIN_AI);
	}
	else
	{
		ft_pb(false, C_RESET);
		ft_pb(false, COIN_EMPTY);
	}
}

void	print_board(t_env *e)
{
	t_index	col;
	t_index	row;

	ft_pb(false, C_CLEAR);
	print_frame_line(e, false);
	row = e->b.row;
	while (row-- > 0)
	{
		ft_pb(false, C_FRAME);
		ft_pb(false, "  \033[0m\033[K");
		col = -1;
		while (++col < e->b.col)
			print_coin(e, e->b.board[col][row]);
		ft_pb(false, C_FRAME);
		ft_pb(false, "  \033[0m\033[K\n");
	}
	print_frame_line(e, true);
	ft_pb(true, NULL);
}
