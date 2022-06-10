/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:48:51 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 20:26:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool horizontal(t_coin **b,
	const t_index col, const t_index row, const t_coin p)
{
	t_index			c;
	t_index			r;

	r = -1;
	while (++r < row - 3)
	{
		c = -1;
		while (++c < col)
			if (b[c][r] == p && b[c][r + 1] == p
					&& b[c][r + 2] == p && b[c][r + 3] == p)
				return (true);
	}
	return (false);
}

static bool	vertical(t_coin **b,
	const t_index col, const t_index row, const t_coin p)
{
	t_index			c;
	t_index			r;

	c = -1;
	while (++c < col - 3)
	{
		r = -1;
		while (++r < row)
			if (b[c][r] == p && b[c + 1][r] == p
					&& b[c + 2][r] == p && b[c + 3][r] == p)
				return (true);
	}
	return (false);
}

static bool	stonk_diagonal(t_coin **b,
	const t_index col, const t_index row, const t_coin p)
{
	t_index			c;
	t_index			r;

	c = 2;
	while (++c < col)
	{
		r = -1;
		while (++r < row - 3)
			if (b[c][r] == p && b[c - 1][r + 1] == p
					&& b[c - 2][r + 2] == p && b[c - 3][r + 3] == p)
				return (true);
	}
	return (false);
}

static bool	not_stonk_diagonal(t_coin **b,
	const t_index col, const t_index row, const t_coin p)
{
	t_index			c;
	t_index			r;

	c = 2;
	while (++c < col)
	{
		r = 2;
		while (++r < row)
			if (b[c][r] == p && b[c - 1][r - 1] == p
					&& b[c - 2][r - 2] == p && b[c - 3][r - 3] == p)
				return (true);
	}
	return (false);
}

int	is_connect(const t_board *b, const t_coin player)
{
	return (horizontal(b->board, b->col, b->row, player)
		|| vertical(b->board, b->col, b->row, player)
		|| stonk_diagonal(b->board, b->col, b->row, player)
		|| not_stonk_diagonal(b->board, b->col, b->row, player));
}
