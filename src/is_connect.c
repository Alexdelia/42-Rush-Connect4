/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:48:51 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 00:06:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool horizontal(short **b,
	const size_t col, const size_t row, const short p)
{
	size_t			c;
	size_t			r;

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

static bool	vertical(short **b,
	const size_t col, const size_t row, const short p)
{
	size_t			c;
	size_t			r;

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

static bool	stonk_diagonal(short **b,
	const size_t col, const size_t row, const short p)
{
	size_t			c;
	size_t			r;

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

static bool	not_stonk_diagonal(short **b,
	const size_t col, const size_t row, const short p)
{
	size_t			c;
	size_t			r;

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

int	is_connect(short **board,
	const size_t col, const size_t row, const short player)
{
	return (horizontal(board, col, row, player)
		|| vertical(board, col, row, player)
		|| stonk_diagonal(board, col, row, player)
		|| not_stonk_diagonal(board, col, row, player));
}
