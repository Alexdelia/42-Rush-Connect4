/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_board_empty_full.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:26:27 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 22:35:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/connect4.h"

bool	is_board_empty(short **board, const size_t col)
{
	size_t	c;

	c = -1;
	while (++c < col)
	{
		if (board[c][0] != NONE)
			return (false);
	}
	return (true);
}

bool	is_board_full(short **board, const size_t col, const size_t row)
{
	size_t	c;

	c = -1;
	while (++c < col)
	{
		if (board[c][row - 1] == NONE)
			return (false);
	}
	return (true);
}
