/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_board_empty_full.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:26:27 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 16:23:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/connect4.h"

// might try inline

bool	is_board_empty(t_env *e)
{
	return (e->n_move);
}

bool	is_board_full(t_env *e)
{
	return (e->n_move == e->col * e->row);
}

bool	is_col_full(short **board, const unsigned short index)
{
	return (e->board
}
