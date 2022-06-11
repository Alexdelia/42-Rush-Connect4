/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:04:04 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 19:51:17 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static bool	is_winning_move(t_board b, const t_index move, const t_coin player)
{
	bool	ret;

	add_coin(&b, move, player);
	ret = is_connect(&b, player);
	remove_coin(&b, move);
	return (ret);
}

static bool	forced(const t_board *b, t_index *index)
{
	*index = -1;
	while (++(*index) < b->col)
		if (!is_col_full(b, *index) && is_winning_move(*b, *index, AI))
			return (true);
	*index = -1;
	while (++(*index) < b->col)
		if (!is_col_full(b, *index) && is_winning_move(*b, *index, USER))
			return (true);
	if (is_board_empty(b))
	{
		*index = (t_index)(b->col / 2);
		return (true);
	}
	return (false);
}

static t_index	nathan_ai(t_env *e);

void	ai(t_env *e)
{
	t_index	index;

	if (!forced(&e->b, &index))
		index = nathan_ai(e);
	if (!add_coin(&e->b, index, AI))
		exit(print_col_full(index));// tmp
}

static t_index	nathan_ai(t_env *e)
{
	t_moves	moves;
	int		i;
	int		curr_score;

	i = 0;
	moves.best_index = 0;
	moves.best_score = -1;
	while (i < e->b.col)
	{
		curr_score = get_score(&e->b, i);
		if (curr_score == WIN_SCORE)
		{
			moves.best_index = i;
			break ;
		}
		if (curr_score > moves.best_score && is_col_full(&e->b, i) == false)
		{
			moves.best_index = i;
			moves.best_score = curr_score;
		}
		i++;
	}
	if (moves.best_score <= 0)
		return (rand() % e->b.col);
	return (moves.best_index);
}

int	get_score(const t_board *b, int index)
{
	int	score;
	int	col_height;
	int	score_tab[4];

	score = 0;
	ft_memset(score_tab, 0, 16);
	col_height = get_col_height(b, index);
	score_tab[0] += score_hor(b, index);
	score_tab[1] += score_diag_up(b, index);
	score_tab[2] += score_diag_down(b, index);
	score_tab[3] += score_down(b, index);
	score = score_tab[0] + score_tab[1] + score_tab[2] + score_tab[3];
	return (score);
}
