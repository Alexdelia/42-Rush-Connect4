/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:58:16 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 17:57:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	init_order(t_env *e)
{
	t_index	i;

	i = -1;
	while (++i < e->b.col)
		g_order[i] = e->b.col / 2 + (1 - 2 * (i % 2)) * (i + 1) / 2;
}

bool	init_board(t_env *e)
{
	t_index	col;
	t_index	row;

	/*e->b.board = (t_coin **)malloc(sizeof(e->b.board) * e->b.col);
	if (!e->b.board)
		return (error("malloc", false));*/
	col = 0;
	while (col < e->b.col)
	{
		/*e->b.board[col] = (t_coin *)malloc(sizeof(e->b.board[col]) * e->b.row);
		if (!e->b.board[col])
		{
			free_board(e->b.board, col);
			return (false);
		}*/
		row = -1;
		while (++row < e->b.row)
			e->b.board[col][row] = NONE;
		col++;
	}
	init_order(e);
	return (true);
}
