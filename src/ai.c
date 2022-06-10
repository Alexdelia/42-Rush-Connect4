/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 23:35:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

static bool	is_winning_move(t_board b, const t_index index)
{
	add_coin(&b, index, b.n_move % 2 + 1);
	return (is_connect(&b, b.n_move % 2 + 1));
}

static int	negamax(t_board b, const t_index next_move, int alpha, int beta)
{
	t_index	index;
	int		score;
	int		max;

	add_coin(&b, next_move, b.n_move % 2 + 1);
	if (is_board_full(&b))
		return (0);
	index = -1;
	while (++index < b.col)
		if (!is_col_full(&b, index) && is_winning_move(b, index))
			return ((b.col * b.row + 1 - b.n_move) / 2);
	max = (b.col * b.row - 1 - b.n_move) / 2;
	if (beta > max)
	{
		beta = max;
		if (alpha >= beta)
			return (beta);
	}
	index = -1;
	while (++index < b.col)
	{
		if (!is_col_full(&b, index))
		{
			score = -negamax(b, index, -beta, -alpha);
			if (score >= beta)
				return (score);
			if (score > alpha)
				alpha = score;
		}
	}
	return (alpha);
}

static t_index	solve(t_board b, int alpha, int beta)
{
	t_index	index;
	t_index	best_index;
	int		score;
	int		max;

	index = -1;
	while (++index < b.col)
		if (!is_col_full(&b, index) && is_winning_move(b, index))
			return (index);
	best_index = 0;
	max = (b.col * b.row - 1 - b.n_move) / 2;
	if (beta > max)
		beta = max;
	index = -1;
	while (++index < b.col)
	{
		if (!is_col_full(&b, index))
		{
			score = -negamax(b, index, -beta, -alpha);
			if (score >= beta)
				return (best_index);
			if (score > alpha)
			{
				alpha = score;
				best_index = index;
				ft_ps("\r");
				ft_pn(alpha);
				ft_ps("  ");
			}
		}
	}
	return (best_index);
}

void	ai(t_env *e)
{
	//	if (!add_coin(&e->b, solve(e->b, -1, 1), AI))	// weak
	if (!add_coin(&e->b, solve(e->b, -e->b.col * e->b.row / 2,
				e->b.col * e->b.row / 2), AI))
	{
		ft_pser(C_BOLD);
		ft_pserc("AI tried to insert coin on full col\n", RED);
		exit(1);	// tmp
	}
}
