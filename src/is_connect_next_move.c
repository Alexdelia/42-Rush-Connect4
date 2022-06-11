/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_connect_next_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:26:20 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 12:48:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool	horizontal(const t_board *b, const t_index col, const t_index row)
{
	long	cur;

	cur = row - 3;
	if (cur < 0)
		cur = 0;
	while (cur <= row && cur + 3 < b->row)
	{
		if (b->board[col][cur] == b->board[col][row]
			&& b->board[col][cur + 1] == b->board[col][row]
			&& b->board[col][cur + 2] == b->board[col][row]
			&& b->board[col][cur + 3] == b->board[col][row])
			return (true);
		cur++;
	}
	return (false);
}

static bool	vertical(const t_board *b, const t_index col, const t_index row)
{
	if (row < 3)
		return (false);
	return (b->board[col][row - 1] == b->board[col][row]
		&& b->board[col][row - 2] == b->board[col][row]
		&& b->board[col][row - 3] == b->board[col][row]);
}

static bool	stonk_diagonal(const t_board *b,
	const t_index col, const t_index row)
{
	long	cur_col;
	long	cur_row;

	cur_row = row - 3;
	if (cur_row < 0)
		cur_row = 0;
	cur_col = col - 3;
	if (cur_col < 0)
		cur_col = 0;
	while (cur_col <= col && cur_row <= row
		&& cur_col + 3 < b->col && cur_row + 3 < b->row)
	{
		if (b->board[cur_col][cur_row] == b->board[col][row]
			&& b->board[cur_col + 1][cur_row + 1] == b->board[col][row]
			&& b->board[cur_col + 2][cur_row + 2] == b->board[col][row]
			&& b->board[cur_col + 3][cur_row + 3] == b->board[col][row])
			return (true);
		cur_col++;
		cur_row++;
	}
	return (false);
}

static bool	not_stonk_diagonal(const t_board *b,
	const t_index col, const t_index row)
{
	long	cur_col;
	long	cur_row;

	cur_row = row + 3;
	if (cur_row >= b->row)
		cur_row = b->row - 1;
	cur_col = col - 3;
	if (cur_col < 0)
		cur_col = 0;
	while (cur_col <= col && cur_row >= row
		&& cur_col + 3 < b->col && cur_row + 3 >= 0)
	{
		if (b->board[cur_col][cur_row] == b->board[col][row]
			&& b->board[cur_col + 1][cur_row - 1] == b->board[col][row]
			&& b->board[cur_col + 2][cur_row - 2] == b->board[col][row]
			&& b->board[cur_col + 3][cur_row - 3] == b->board[col][row])
			return (true);
		cur_col++;
		cur_row--;
	}
	return (false);
}

bool	is_connect_next_move(const t_board *b, const t_index move)
{
	t_index	r;

	r = b->row - 1;
	while (r > 0 && b->board[move][r] == NONE)
		r++;
	return (horizontal(b, move, r)
		|| vertical(b, move, r)
		|| stonk_diagonal(b, move, r)
		|| not_stonk_diagonal(b, move, r));
}
