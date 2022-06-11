/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:58:16 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 19:12:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
bool	init_board(t_env *e)
{
	t_index	col;
	t_index	row;

	e->b.board = malloc(sizeof(e->b.board) * (e->b.col + 1));
	if (!e->b.board)
		return (error("malloc", false));
	col = 0;
	while (col < e->b.col)
	{
		e->b.board[col] = malloc(sizeof(e->b.board[col]) * (e->b.row + 1));
		if (!e->b.board[col])
		{
			free_board(e->b.board, col);
			return (false);
		}
		row = -1;
		while (++row < e->b.row)
			e->b.board[col][row] = NONE;
		col++;
	}
	return (true);
}
