/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:58:16 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 10:16:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/connect4.h"

bool	init_board(t_env *e)
{
	size_t	col;
	size_t	row;

	e->board = (short **)malloc(sizeof(e->board) * e->col);
	if (!e->board)
		return (error("malloc", false));
	col = 0;
	while (col < e->col)
	{
		e->board[col] = (short *)malloc(sizeof(e->board[col]) * e->row);
		if (!e->board[col])
		{
			free_board(e->board, col);
			return (false);
		}
		row = -1;
		while (++row < e->row)
			e->board[col][row] = NONE;
		col++;
	}
	return (true);
}
