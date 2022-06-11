/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 14:01:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool	is_winning_move(t_board b, const t_index move, const t_coin player)
{
	add_coin(&b, move, player);
	return (is_connect(&b, player));
}

static t_index	solve(const t_board *b)
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
	ft_pserc("unforced", C_CYAN);
	index = rand() % b->col;
	while (is_col_full(b, index))
		index = rand() % b->col;
	return (index);
}

void	ai(t_env *e)
{
	if (!add_coin(&e->b, solve(&e->b), AI))
	{
		ft_pser(C_BOLD);
		ft_pserc("AI tried to insert coin on full col\n", RED);
		exit(1);	// tmp
	}
}
