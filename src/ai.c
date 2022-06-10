/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 21:44:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool	is_winning_move(t_board b, const t_index index)
{
	add_coin(&b, index, b.n_move % 2 + 1);
	return (is_connect(&b, b.n_move % 2 + 1));
}

static int	negamax(t_board b, const t_index next_move)
{
	t_index	index;
	int		best_score;
	int		tmp;

	add_coin(&b, next_move, b.n_move % 2 + 1);
	if (is_board_full(&b))
		return (0);
	index = -1;
	while (++index < b.col)
		if (!is_col_full(&b, index) && is_winning_move(b, index))
			return ((b.col * b.row + 1 - b.n_move) / 2);
	best_score = -b.col * b.row;
	index = -1;
	while (++index < b.col)
	{
		if (!is_col_full(&b, index))
		{
			tmp = -negamax(b, index);
			if (tmp > best_score)
				best_score = tmp;
		}
	}
	return (best_score);
}

static t_index	solve(t_board b)
{
	t_index	index;
	t_index	best_index;
	int		best_score;
	int		tmp;

	index = -1;
	while (++index < b.col)
		if (!is_col_full(&b, index) && is_winning_move(b, index))
			return (index);
	best_score = -b.col * b.row;
	index = -1;
	while (++index < b.col)
	{
		if (!is_col_full(&b, index))
		{
			tmp = -negamax(b, index);
			if (tmp > best_score)
			{
				best_score = tmp;
				best_index = index;
			}
		}
	}
	return (best_index);
}

void	ai(t_env *e)
{
	if (!add_coin(&e->b, solve(e->b), AI))
	{
		ft_pser(C_BOLD);
		ft_pserc("AI tried to insert coin on full col\n", RED);
		exit(1);	// tmp
	}
}
