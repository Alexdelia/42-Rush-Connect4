/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_hor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:31:34 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/11 17:50:14 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "connect4.h"

static int	score_hor_right(const t_board *b, t_index index, t_index height);
static int	score_hor_left(const t_board *b, t_index index, t_index height);

int	score_hor(const t_board *b, t_index index)
{
	t_index	height;
	int		right;
	int		left;

	height = get_col_height(b, index);
	right = score_hor_right(b, index, height);
	left = score_hor_left(b, index, height);
	return (right + left);
}

static int	score_hor_right(const t_board *b, t_index index, t_index height)
{
	int	i;

	i = 1;
	if (index == b->col 
		|| index + 1 == b->col || b->board[index + 1][height] == 0)
		return (0);
	if (!(b->board[index + 1][height] == b->board[index + 2][height]))
		return (0);
	if (b->board[index + 1][height] == AI)
		return (10);
	else if (b->board[index + 1][height] == USER)
		return (15);
	return (0);
}

static int	score_hor_left(const t_board *b, t_index index, t_index height)
{
	int	i;

	i = 1;
	if (index == 0
		|| index - 1 == 0 || b->board[index - 1][height] == 0)
		return (0);
	if (!(b->board[index - 1][height] == b->board[index - 2][height]))
		return (0);	
	if (b->board[index - 1][height] == AI)
		return (10);
	else if (b->board[index - 1][height] == USER)
		return (15);
	return (0);
}