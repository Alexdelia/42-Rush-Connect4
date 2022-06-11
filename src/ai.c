/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 17:57:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static bool	is_winning_move(t_board b, const t_index move, const t_coin player)
{
	add_coin(&b, move, player);
	return (is_connect(&b, player));
}

static int	negamax(t_board b, const t_index next_move, int alpha, int beta,
	const t_coin player, const unsigned short node)
{
	t_index	index;
	int		score;
	int		max;

	add_coin(&b, next_move, player);
	if (is_board_full(&b) || node > MAX_NODE)
		return (0);
	index = -1;
	while (++index < b.col)
		if (!is_col_full(&b, index) && is_winning_move(b, index, player))
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
		if (!is_col_full(&b, g_order[index]))
		{
			if (player == AI)
				score = -negamax(b, g_order[index], -beta, -alpha, USER, node + 1);
			else if (player == USER)
				score = -negamax(b, g_order[index], -beta, -alpha, AI, node + 1);
			if (score >= beta)
				return (score);
			if (score > alpha)
				alpha = score;
		}
	}
	return (alpha);
}

static t_index	init_negamax(t_board b, int alpha, int beta)
{
	t_index	index;
	t_index	best_index;
	int		score;
	int		max;

	index = -1;
	while (++index < b.col)
		if (!is_col_full(&b, index) && is_winning_move(b, index, AI))
			return (index);
	best_index = MAX_SIZE;
	max = (b.col * b.row - 1 - b.n_move) / 2;
	if (beta > max)
		beta = max;
	index = -1;
	while (++index < b.col)
	{
		if (!is_col_full(&b, g_order[index]))
		{
			if (best_index == MAX_SIZE)
				best_index = g_order[index];
			score = -negamax(b, g_order[index], -beta, -alpha, USER, 0);
			if (score >= beta)
				return (best_index);
			if (score > alpha)
			{
				alpha = score;
				best_index = g_order[index];
				/*ft_ps("\r");
				ft_pn(alpha);
				ft_ps("  ");*/
			}
		}
	}
	ft_pner(score);
	ft_pser("\n");
	ft_pner(index);
	ft_pser("\n\n");
	return (best_index);
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
	if (is_board_empty(b))
		return ((t_index)(b->col / 2));
	if (b->n_move < START_BACKTRACK)
	{
		index = rand() % b->col;
		while (is_col_full(b, index))
			index = rand() % b->col;
	}
	else
	{
		//	ft_pserc("unforced\n", C_CYAN);
		//	index = init_negamax(*b, -1, 1);	// weak
		index = init_negamax(*b, -b->col * b->row / 2, b->col * b->row / 2);
	}
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
