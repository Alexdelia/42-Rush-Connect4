/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_diag_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:48:53 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/11 23:10:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int	score_diag_down_left(const t_board *b,
				const t_index index, const t_index height);
static int	score_diag_down_right(const t_board *b,
				const t_index index, const t_index height);

int	score_diag_down(const t_board *b, const t_index index)
{
	t_index	height;
	int		right;
	int		left;

	height = get_col_height(b, index);
	right = score_diag_down_right(b, index, height);
	left = score_diag_down_left(b, index, height);
	return (right + left);
}

static int	score_diag_down_right(const t_board *b,
	const t_index index, const t_index height)
{
	if (index + 2 >= b->col || height == 0
		|| height - 1 == 0
		|| height - 2 == 0)
		return (0);
	if (!(b->board[index + 1][height - 1] == b->board[index + 2][height - 2]))
		return (0);
	if (b->board[index + 1][height - 1] == AI)
		return (20);
	else if (b->board[index + 1][height - 1] == USER)
		return (15);
	return (0);
}

static int	score_diag_down_left(const t_board *b,
	const t_index index, const t_index height)
{
	if (index == 0 || height == 0
		|| index - 1 == 0 || height - 1 == 0
		|| index - 2 == 0 || height - 2 == 0)
		return (0);
	if (!(b->board[index - 1][height - 1] == b->board[index - 2][height - 2]))
		return (0);	
	if (b->board[index - 1][height - 1] == AI)
		return (20);
	else if (b->board[index - 1][height - 1] == USER)
		return (15);
	return (0);
}
