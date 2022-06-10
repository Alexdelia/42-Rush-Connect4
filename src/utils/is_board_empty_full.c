/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_board_empty_full.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:26:27 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 21:55:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/connect4.h"

// might try inline

bool	is_board_empty(const t_board *b)
{
	return (!b->n_move);
}

bool	is_board_full(const t_board *b)
{
	return (b->n_move == b->col * b->row);
}

bool	is_col_full(const t_board *b, const t_index index)
{
	return (b->board[index][b->row - 1] != NONE);
}
