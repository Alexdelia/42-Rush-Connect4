/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_diag_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:53:19 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/11 17:50:07 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "connect4.h"

static int	score_diag_up_right(const t_board *b, t_index index, t_index height);
static int	score_diag_up_left(const t_board *b, t_index index, t_index height);

int	score_diag_up(const t_board *b, t_index index)
{
	t_index	height;
	int		right;
	int		left;

	height = get_col_height(b, index);
	right = score_diag_up_right(b, index, height);
	left = score_diag_up_left(b, index, height);
	return (right + left);
}

static int	score_diag_up_right(const t_board *b, t_index index, t_index height)
{
	int	i;

	i = 1;
	if (index == b->col || get_col_height(b, index + 1) <= height
		|| index + 1 == b->col || b->board[index + 1][height] == 0
		|| height + 1 == b->row || height == b->row)
		return (0);
	if (!(b->board[index + 1][height + 1] == b->board[index + 2][height + 2]))
		return (0);
	if (b->board[index + 1][height + 1] == AI)
		return (10);
	else if (b->board[index + 1][height + 1] == USER)
		return (15);
	return (0);
}

static int	score_diag_up_left(const t_board *b, t_index index, t_index height)
{
	int	i;

	i = 1;
	if (index == 0 || get_col_height(b, index - 1) <= height
		|| index - 1 == 0 || b->board[index - 1][height] == 0
		|| height + 1 == b->row || height == b->row)
		return (0);
	if (!(b->board[index - 1][height + 1] == b->board[index - 2][height + 2]))
		return (0);	
	if (b->board[index - 1][height + 1] == AI)
		return (10);
	else if (b->board[index - 1][height + 1] == USER)
		return (15);
	return (0);
}