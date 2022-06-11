/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:48:51 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 17:46:08 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static bool	horizontal(const t_board *b, const t_coin p)
{
	t_index			c;
	t_index			r;

	r = -1;
	while (++r < b->row - 3)
	{
		c = -1;
		while (++c < b->col)
			if (b->board[c][r] == p && b->board[c][r + 1] == p
					&& b->board[c][r + 2] == p && b->board[c][r + 3] == p)
				return (true);
	}
	return (false);
}

static bool	vertical(const t_board *b, const t_coin p)
{
	t_index			c;
	t_index			r;

	c = -1;
	while (++c < b->col - 3)
	{
		r = -1;
		while (++r < b->row)
			if (b->board[c][r] == p && b->board[c + 1][r] == p
					&& b->board[c + 2][r] == p && b->board[c + 3][r] == p)
				return (true);
	}
	return (false);
}

static bool	stonk_diagonal(const t_board *b, const t_coin p)
{
	t_index			c;
	t_index			r;

	c = 2;
	while (++c < b->col)
	{
		r = -1;
		while (++r < b->row - 3)
			if (b->board[c][r] == p && b->board[c - 1][r + 1] == p
					&& b->board[c - 2][r + 2] == p
					&& b->board[c - 3][r + 3] == p)
				return (true);
	}
	return (false);
}

static bool	not_stonk_diagonal(const t_board *b, const t_coin p)
{
	t_index			c;
	t_index			r;

	c = 2;
	while (++c < b->col)
	{
		r = 2;
		while (++r < b->row)
			if (b->board[c][r] == p && b->board[c - 1][r - 1] == p
					&& b->board[c - 2][r - 2] == p
					&& b->board[c - 3][r - 3] == p)
				return (true);
	}
	return (false);
}

bool	is_connect(const t_board *b, const t_coin player)
{
	return (horizontal(b, player)
		|| vertical(b, player)
		|| stonk_diagonal(b, player)
		|| not_stonk_diagonal(b, player));
}
