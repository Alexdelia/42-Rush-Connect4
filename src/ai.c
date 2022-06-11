/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 18:26:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static bool	is_winning_move(t_board b, const t_index move, const t_coin player)
{
	add_coin(&b, move, player);
	return (is_connect(&b, player));
}

static t_index	solve(const t_board *b)
{
	t_index	index;

	index = rand() % b->col;
	while (is_col_full(b, index))
		index = rand() % b->col;

	return (index);
}

static t_index	forced(const t_board *b)
{
	t_index	index;

	index = -1;
	while (++index < b->col)
		if (!is_col_full(b, index) && is_winning_move(*b, index, AI))
			return (index);
	index = -1;
	while (++index < b->col)
		if (!is_col_full(b, index) && is_winning_move(*b, index, USER))
			return (index);
	if (is_board_empty(b))
		return ((t_index)(b->col / 2));
	return (MAX_SIZE);
}

void	ai(t_env *e)
{
	t_index	index;

	index = forced(&e->b);
	if (index == MAX_SIZE)
		index = solve(&e->b);

	if (!add_coin(&e->b, index, AI))
		exit(print_col_full(index));// tmp
}
